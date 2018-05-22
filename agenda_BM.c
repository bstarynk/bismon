// file agenda_BM.c
/***
    BISMON 
    Copyright © 2018 Basile Starynkevitch (working at CEA, LIST, France)
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
***/

#include "bismon.h"
#include "agenda_BM.const.h"

#define TI_MAGICNUM_BM 0x67d1
/// thread-local data for work threads
struct threadinfo_stBM
{
  unsigned ti_magic;
  short ti_rank;
  atomic_bool ti_stop;
  atomic_bool ti_gc;
  pthread_t ti_pthread;
  double ti_thstartelapsedtime;
  double ti_thstartcputime;
};                              /* end struct threadinfo_stBM */



static struct threadinfo_stBM ti_array_BM[MAXNBWORKJOBS_BM + 2];
static pthread_mutex_t ti_agendamtx_BM;
static pthread_cond_t ti_agendacond_BM;
static int ti_nbworkers_BM;
static atomic_bool ti_needgc_BM;
static atomic_int ti_countendedthreads_BM;
static struct hashsetobj_stBM *ti_veryhigh_taskhset_BM;
static struct hashsetobj_stBM *ti_high_taskhset_BM;
static struct hashsetobj_stBM *ti_normal_taskhset_BM;
static struct hashsetobj_stBM *ti_low_taskhset_BM;
static struct hashsetobj_stBM *ti_verylow_taskhset_BM;

// agenda defer data is under ti_agendamtx_BM lock
#define AGD_MAGIC_BM 996723975  /*0x3b68cd07 */
struct agenda_defer_stBM
{
  unsigned agd_magic;           // always AGD_MAGIC_BM
  unsigned agd_nbval;
  deferredaftergc_sigBM *agd_rout;
  void *agd_data;
  struct agenda_defer_stBM *agd_next;
  value_tyBM agd_valarr[];      /* useful length is agd_nbval */
};
#define AGD_MAXCOUNT_BM 0x1ffff

static struct agenda_defer_stBM *agd_first_BM;
static struct agenda_defer_stBM *agd_last_BM;


static void *run_agendaworker_BM (void *);
static void run_agenda_internal_tasklet_BM (objectval_tyBM * obtk,
                                            struct failurelockset_stBM *flh);
static objectval_tyBM *choose_task_internal_agenda_BM (void);
static struct hashsetobj_stBM *maybe_reorganize_taskhshet_agenda_BM     //
  (struct hashsetobj_stBM *tkhset);


void
initialize_agenda_BM (void)
{
  pthread_mutex_init (&ti_agendamtx_BM, NULL);
  pthread_cond_init (&ti_agendacond_BM, NULL);
}                               /* end initialize_agenda_BM */


#define GCWAITMILLISECONDS_BM 550
#define TASKWAITMILLISECONDS_BM 300
#define STOPWAITMILLISECONDS_BM 440
#define WORKTHREADSTACKSIZE_BM (10*1024*1024)
// the work routine, passed to pthread_create
void *
run_agendaworker_BM (void *ad)
{
  intptr_t tix = (intptr_t) ad;
  ASSERT_BM (tix > 0 && tix <= MAXNBWORKJOBS_BM && tix <= ti_nbworkers_BM);
  char thnambuf[16];
  memset (thnambuf, 0, sizeof (thnambuf));
  snprintf (thnambuf, sizeof (thnambuf), "bmwth#%d", (int) tix);
  pthread_setname_np (pthread_self (), thnambuf);
  curthreadinfo_BM = ti_array_BM + tix;
  ASSERT_BM (curthreadinfo_BM->ti_magic == TI_MAGICNUM_BM);
  ASSERT_BM (curthreadinfo_BM->ti_rank == (short) tix);
  usleep (5 + 3 * tix);
  // be sure that clocktime_BM(CLOCK_THREAD_CPUTIME_ID) is positive, so warmup the CPU
  {
    volatile double x = tix * 0.02 + 0.001;
    while (clocktime_BM (CLOCK_THREAD_CPUTIME_ID) <= 0.0 && x < 0.8)
      {
        // some useless computation
        x +=
          0.25 * sin (x + tix * 0.0001) + 1.0e-6 + 1.0e-7 * (getpid () % 16);
      };
  }
  usleep (40 + 17 * tix);
  long loopcnt = 0;
  for (;;)
    {
      loopcnt++;
      objectval_tyBM *taskob = NULL;
      if (atomic_load (&curthreadinfo_BM->ti_stop))
        break;
      /// run the GC if needed
      if (atomic_load (&ti_needgc_BM))
        {
          // wait for GC to terminate
          NONPRINTF_BM
            ("run_agendaworker tix#%d needgc start tid#%ld elapsed %.3f s",
             (int) tix, (long) gettid_BM (), elapsedtime_BM ());
          atomic_store (&curthreadinfo_BM->ti_gc, true);
          pthread_cond_broadcast (&ti_agendacond_BM);
          do
            {
              NONPRINTF_BM
                ("run_agendaworker tix#%d needgc timedwait tid#%ld elapsed %.3f s",
                 (int) tix, (long) gettid_BM (), elapsedtime_BM ());
              pthread_mutex_lock (&ti_agendamtx_BM);
              {
                struct timespec ts = { 0, 0 };
                get_realtimespec_delayedms_BM (&ts, GCWAITMILLISECONDS_BM);
                pthread_cond_timedwait (&ti_agendacond_BM, &ti_agendamtx_BM,
                                        &ts);
              }
              pthread_mutex_unlock (&ti_agendamtx_BM);
              NONPRINTF_BM
                ("run_agendaworker tix#%d needgcendloop tid#%ld elapsed %.3f s",
                 (int) tix, (long) gettid_BM (), elapsedtime_BM ());
            }
          while (atomic_load (&curthreadinfo_BM->ti_gc));
          NONPRINTF_BM
            ("run_agendaworker tix#%d needgc done tid#%ld elapsed %.3f s",
             (int) tix, (long) gettid_BM (), elapsedtime_BM ());
        }
      /// choose a task to run
      {
        pthread_mutex_lock (&ti_agendamtx_BM);
        taskob = choose_task_internal_agenda_BM ();
        pthread_mutex_unlock (&ti_agendamtx_BM);
        NONPRINTF_BM
          ("run_agendaworker tix%d choose tid#%ld elapsed %.3f s taskob %s",
           (int) tix, (long) gettid_BM (), elapsedtime_BM (),
           objectdbg_BM (taskob));
        if (taskob)
          {
            long flspace[12];
            memset (&flspace, 0, sizeof (flspace));
            initialize_failurelockset_BM ((struct failurelockset_stBM *)
                                          &flspace, sizeof (flspace));
            curthreadinfo_BM->ti_thstartcputime =
              clocktime_BM (CLOCK_THREAD_CPUTIME_ID);
            curthreadinfo_BM->ti_thstartelapsedtime =
              clocktime_BM (CLOCK_MONOTONIC);
            run_agenda_internal_tasklet_BM (taskob,
                                            (struct failurelockset_stBM *)
                                            &flspace);
            curthreadinfo_BM->ti_thstartcputime = 0.0;
            curthreadinfo_BM->ti_thstartelapsedtime = 0.0;
            destroy_failurelockset_BM ((struct failurelockset_stBM *)
                                       &flspace);
            NONPRINTF_BM
              ("run_agendaworker tix%d didrun tid#%ld elapsed %.3f s",
               (int) tix, (long) gettid_BM (), elapsedtime_BM ());
          }
        else
          {                     // no task to run
            NONPRINTF_BM
              ("run_agendaworker tix%d tid#%ld notask elapsed %.3f s",
               (int) tix, (long) gettid_BM (), elapsedtime_BM ());
            pthread_mutex_lock (&ti_agendamtx_BM);
            {
              struct timespec ts = { 0, 0 };
              get_realtimespec_delayedms_BM (&ts, TASKWAITMILLISECONDS_BM);
              pthread_cond_timedwait (&ti_agendacond_BM, &ti_agendamtx_BM,
                                      &ts);
            }
            pthread_mutex_unlock (&ti_agendamtx_BM);
            NONPRINTF_BM
              ("run_agendaworker tix%d tid#%ld notask after elapsed %.3f s",
               (int) tix, (long) gettid_BM (), elapsedtime_BM ());
          }
      }
    };                          /* end forever */
  curthreadinfo_BM = NULL;
  atomic_fetch_add (&ti_countendedthreads_BM, 1);
  pthread_cond_broadcast (&ti_agendacond_BM);
  usleep (1);
  return NULL;
}                               /* end run_agendaworker_BM */

int
agenda_nb_work_jobs_BM (void)
{
  return ti_nbworkers_BM;
}                               /* end agenda_nb_work_jobs_BM */

extern double taskletcputime_BM (void) __attribute__ ((optimize ("-O3")));
extern double taskletelapsedtime_BM (void) __attribute__ ((optimize ("-O3")));

double
taskletcputime_BM (void)
{
  double ths = 0.0;
  if (curthreadinfo_BM && (ths = curthreadinfo_BM->ti_thstartcputime) > 0.0)
    return clocktime_BM (CLOCK_THREAD_CPUTIME_ID) - ths;
  return NAN;
}                               // end taskletcputime_BM

double
taskletelapsedtime_BM (void)
{
  double ths = 0.0;
  if (curthreadinfo_BM
      && (ths = curthreadinfo_BM->ti_thstartelapsedtime) > 0.0)
    return clocktime_BM (CLOCK_MONOTONIC) - ths;
  return NAN;
}                               // end taskletelapsedtime_BM



static struct hashsetobj_stBM *
maybe_reorganize_taskhshet_agenda_BM (struct hashsetobj_stBM *hset)
{
  ASSERT_BM (valtype_BM (hset) == typayl_hashsetobj_BM);
  unsigned alsiz = ((typedhead_tyBM *) hset)->rlen;
  unsigned ucnt = ((typedsize_tyBM *) hset)->size;
  int r = g_random_int ();
  if (alsiz > 20 && 3 * ucnt < alsiz && r % 8 == 0)
    return hashsetobj_grow_BM (hset, 1);
  else if (ucnt == 0 && r % 16 == 1)
    return NULL;
  else if (4 * ucnt + 10 < 3 * alsiz && r % 8 == 0)
    return hashsetobj_grow_BM (hset, ucnt / 4 + 2);
  return hset;
}                               /* end maybe_reorganize_taskhshet_agenda_BM */


objectval_tyBM *
choose_task_internal_agenda_BM (void)
{
  // the ti_agendamtx_BM has been locked by caller, run_agendaworker_BM
  int r = g_random_int ();
  objectval_tyBM *taskob = NULL;
  if (!taskob && ti_veryhigh_taskhset_BM)
    {
      objectval_tyBM *curtaskob =
        hashsetobj_take_random_BM (ti_veryhigh_taskhset_BM);
      if (curtaskob)
        {
          ti_veryhigh_taskhset_BM =
            maybe_reorganize_taskhshet_agenda_BM (ti_veryhigh_taskhset_BM);
          taskob = curtaskob;
        }
    }
  if ((!taskob || r % 32 == 0) && ti_high_taskhset_BM)
    {
      objectval_tyBM *curtaskob =
        hashsetobj_take_random_BM (ti_high_taskhset_BM);
      if (curtaskob)
        {
          ti_high_taskhset_BM =
            maybe_reorganize_taskhshet_agenda_BM (ti_high_taskhset_BM);
          taskob = curtaskob;
        }
    }
  if ((!taskob || r % 32 == 1) && ti_normal_taskhset_BM)
    {
      objectval_tyBM *curtaskob =
        hashsetobj_take_random_BM (ti_normal_taskhset_BM);
      if (curtaskob)
        {
          ti_normal_taskhset_BM =
            maybe_reorganize_taskhshet_agenda_BM (ti_normal_taskhset_BM);
          taskob = curtaskob;
        }
    }
  if ((!taskob || r % 32 == 2) && ti_low_taskhset_BM)
    {
      objectval_tyBM *curtaskob =
        hashsetobj_take_random_BM (ti_low_taskhset_BM);
      if (curtaskob)
        {
          ti_low_taskhset_BM =
            maybe_reorganize_taskhshet_agenda_BM (ti_low_taskhset_BM);
          taskob = curtaskob;
        }
    }
  if ((!taskob || r % 32 == 3) && ti_verylow_taskhset_BM)
    {
      objectval_tyBM *curtaskob =
        hashsetobj_take_random_BM (ti_verylow_taskhset_BM);
      if (curtaskob)
        {
          ti_verylow_taskhset_BM =
            maybe_reorganize_taskhshet_agenda_BM (ti_verylow_taskhset_BM);
          taskob = curtaskob;
        }
    }
  return taskob;
}                               /* end choose_task_internal_agenda_BM */


void
gcmarkagenda_BM (struct garbcoll_stBM *gc)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  pthread_mutex_lock (&ti_agendamtx_BM);
  if (ti_veryhigh_taskhset_BM)
    hashsetgcmark_BM (gc, ti_veryhigh_taskhset_BM, NULL);
  if (ti_high_taskhset_BM)
    hashsetgcmark_BM (gc, ti_high_taskhset_BM, NULL);
  if (ti_normal_taskhset_BM)
    hashsetgcmark_BM (gc, ti_normal_taskhset_BM, NULL);
  if (ti_low_taskhset_BM)
    hashsetgcmark_BM (gc, ti_low_taskhset_BM, NULL);
  if (ti_verylow_taskhset_BM)
    hashsetgcmark_BM (gc, ti_verylow_taskhset_BM, NULL);
  if (agd_first_BM != NULL)
    {
      ASSERT_BM (agd_last_BM != NULL);
      unsigned agdcount = 0;
      unsigned agdvalcount = 0;
      for (struct agenda_defer_stBM * agd = agd_first_BM; agd != NULL;
           agd = agd->agd_next)
        {
          ASSERT_BM (agd->agd_magic == AGD_MAGIC_BM);
          unsigned nbv = agd->agd_nbval;
          for (unsigned vix = 0; vix < nbv; vix++)
            {
              agdvalcount++;
              VALUEGCPROC_BM (gc, agd->agd_valarr[vix], 0);
              if (agdvalcount > MILLION_BM)
                FATAL_BM ("too many agenda defer values %u", agdvalcount);
            }
          agdcount++;
          if (agdcount > AGD_MAXCOUNT_BM)
            FATAL_BM ("too many agenda defer %u", agdcount);
        }
    };
  pthread_mutex_unlock (&ti_agendamtx_BM);
}                               /* end gcmarkagenda_BM */

void
start_agenda_work_threads_BM (int nbjobs)
{
  ASSERT_BM (nbjobs >= MINNBWORKJOBS_BM && nbjobs < MAXNBWORKJOBS_BM);
  ASSERT_BM (pthread_self () == mainthreadid_BM);
  ti_nbworkers_BM = nbjobs;
  pthread_attr_t at = { };
  pthread_attr_init (&at);
  pthread_attr_setdetachstate (&at, PTHREAD_CREATE_DETACHED);
  pthread_attr_setstacksize (&at, WORKTHREADSTACKSIZE_BM);
  for (int ix = 1; ix <= nbjobs; ix++)
    {
      ti_array_BM[ix].ti_magic = TI_MAGICNUM_BM;
      ti_array_BM[ix].ti_rank = ix;
      atomic_init (&ti_array_BM[ix].ti_stop, false);
      atomic_init (&ti_array_BM[ix].ti_gc, false);
      ti_array_BM[ix].ti_pthread = (pthread_t) 0;
      ti_array_BM[ix].ti_thstartelapsedtime = 0.0;
      ti_array_BM[ix].ti_thstartcputime = 0.0;
    };
  usleep (5);
  for (int ix = 1; ix <= nbjobs; ix++)
    {
      usleep (25);
      pthread_create (&ti_array_BM[ix].ti_pthread, &at,
                      run_agendaworker_BM, (void *) (intptr_t) ix);
    }
  usleep (5);
  pthread_attr_destroy (&at);
}                               /* end start_agenda_work_threads_BM */


void
stop_agenda_work_threads_BM (void)
{
  int nbwth = ti_nbworkers_BM;
  NONPRINTF_BM
    ("stop_agenda_work_threads start nbwth=%d tid#%ld elapsed %.3f s", nbwth,
     (long) gettid_BM (), elapsedtime_BM ());
  {
    pthread_mutex_lock (&ti_agendamtx_BM);
    for (int tix = 1; tix <= nbwth; tix++)
      atomic_store (&ti_array_BM[tix].ti_stop, true);
    pthread_mutex_unlock (&ti_agendamtx_BM);
  }
  usleep (5);
  pthread_cond_broadcast (&ti_agendacond_BM);
  usleep (1000);
  do
    {
      usleep (10);
      pthread_mutex_lock (&ti_agendamtx_BM);
      struct timespec ts = { 0, 0 };
      get_realtimespec_delayedms_BM (&ts, STOPWAITMILLISECONDS_BM);
      NONPRINTF_BM ("stop_agenda_work_threads tid#%ld", (long) gettid_BM ());
      pthread_cond_timedwait (&ti_agendacond_BM, &ti_agendamtx_BM, &ts);
      pthread_mutex_unlock (&ti_agendamtx_BM);
    }
  while (atomic_load (&ti_countendedthreads_BM) < nbwth);
}                               /* end stop_agenda_work_threads_BM */

void
agenda_suspend_for_gc_BM (void)
{
  ASSERT_BM (curthreadinfo_BM == NULL);
  atomic_store (&ti_needgc_BM, true);
  pthread_cond_broadcast (&ti_agendacond_BM);
  bool alldoinggc = false;
  int nbwth = ti_nbworkers_BM;
  long loopcnt = 0;
  NONPRINTF_BM ("agenda_suspend_for_gc_BM nwth=%d", nbwth);
  while (!alldoinggc)
    {
      alldoinggc = false;
      int wix = 0;
      loopcnt++;
      NONPRINTF_BM
        ("agenda_suspend_for_gc_BM elapsed %.3f s tid%ld loopcnt%ld",
         elapsedtime_BM (), (long) gettid_BM (), loopcnt);
      pthread_mutex_lock (&ti_agendamtx_BM);
      for (int tix = 1; tix <= nbwth && !wix; tix++)
        if (!atomic_load (&ti_array_BM[tix].ti_gc))
          wix = tix;
      pthread_mutex_unlock (&ti_agendamtx_BM);
      NONPRINTF_BM
        ("agenda_suspend_for_gc_BM tid#%ld wix=%d elapsed %.3f s",
         (long) gettid_BM (), wix, elapsedtime_BM ());
      if (wix > 0)
        {
          struct timespec ts = { 0, 0 };
          get_realtimespec_delayedms_BM (&ts, GCWAITMILLISECONDS_BM);
          NONPRINTF_BM
            ("agenda_suspend_for_gc_BM tid#%ld wix=%d before timedwait elapsed %.3f s",
             (long) gettid_BM (), wix, elapsedtime_BM ());
          pthread_mutex_lock (&ti_agendamtx_BM);
          pthread_cond_timedwait (&ti_agendacond_BM, &ti_agendamtx_BM, &ts);
          pthread_mutex_unlock (&ti_agendamtx_BM);
          NONPRINTF_BM
            ("agenda_suspend_for_gc_BM tid#%ld after timedwait elapsed %.3f s",
             (long) gettid_BM (), elapsedtime_BM ());
        }
      else
        break;
    }
  NONPRINTF_BM ("agenda_suspend_for_gc_BM done");
}                               /* end agenda_suspend_for_gc_BM */

void
agenda_continue_after_gc_BM (void)
{
  ASSERT_BM (curthreadinfo_BM == NULL);
  int nbwth = ti_nbworkers_BM;
  NONPRINTF_BM ("agenda_continue_after_gc tid#%ld elapsed %.3f s",
                (long) gettid_BM (), elapsedtime_BM ());
  atomic_store (&ti_needgc_BM, false);
  {
    pthread_mutex_lock (&ti_agendamtx_BM);
    for (int tix = 1; tix <= nbwth; tix++)
      atomic_store (&ti_array_BM[tix].ti_gc, false);
    pthread_mutex_unlock (&ti_agendamtx_BM);
  }
  pthread_cond_broadcast (&ti_agendacond_BM);
  atomic_store (&ti_needgc_BM, false);
  usleep (1);
  NONPRINTF_BM ("agenda_continue_after_gc end tid#%ld elapsed %.3f s",
                (long) gettid_BM (), elapsedtime_BM ());
}                               /* end agenda_continue_after_gc_BM */

void
agenda_run_deferred_after_gc_BM (void)
{
  struct agenda_defer_stBM *oldfirst = NULL;
  struct agenda_defer_stBM *oldlast = NULL;
  struct failurehandler_stBM *oldflh =
    (struct failurehandler_stBM *) curfailurehandle_BM;
  curfailurehandle_BM = NULL;
  pthread_mutex_lock (&ti_agendamtx_BM);
  oldfirst = agd_first_BM;
  oldlast = agd_last_BM;
  agd_first_BM = NULL;
  agd_last_BM = NULL;
  pthread_mutex_unlock (&ti_agendamtx_BM);
  struct agenda_defer_stBM *nextagd = NULL;
  unsigned agdcount = 0;
  for (struct agenda_defer_stBM * curagd = oldfirst; curagd != NULL;
       curagd = nextagd)
    {
      ASSERT_BM (curagd->agd_magic == AGD_MAGIC_BM);
      nextagd = curagd->agd_next;
      ASSERT_BM (nextagd != NULL || curagd == oldlast);
      agdcount++;
      ASSERT_BM (curagd->agd_rout != NULL);
      (*curagd->agd_rout) (curagd->agd_valarr, curagd->agd_nbval,
                           curagd->agd_data);
      memset (curagd, 0, sizeof (*curagd));
      free (curagd), curagd = NULL;
      ASSERT_BM (agdcount <= AGD_MAXCOUNT_BM);
    }
  curfailurehandle_BM = oldflh;
}                               /* end agenda_run_deferred_after_gc_BM */

void
agenda_defer_after_gc_BM (deferredaftergc_sigBM * rout,
                          value_tyBM * valarr, unsigned nbval, void *data)
{
  ASSERT_BM (rout != NULL);
  ASSERT_BM (valarr != NULL || nbval == 0);
  ASSERT_BM (nbval < 0x3ffff);
  unsigned siz = prime_above_BM (nbval);
  struct agenda_defer_stBM *newagd =
    malloc (sizeof (struct agenda_defer_stBM) + siz * sizeof (value_tyBM));
  if (!newagd)
    FATAL_BM ("failed to malloc newagd for %d values", siz);
  memset (newagd, 0,
          sizeof (struct agenda_defer_stBM) + siz * sizeof (value_tyBM));
  newagd->agd_magic = AGD_MAGIC_BM;
  newagd->agd_nbval = nbval;
  newagd->agd_rout = rout;
  newagd->agd_data = data;
  if (nbval > 0)
    memcpy (newagd->agd_valarr, valarr, nbval * sizeof (value_tyBM));
  pthread_mutex_lock (&ti_agendamtx_BM);
  if (agd_first_BM == NULL)
    {
      ASSERT_BM (agd_last_BM == NULL);
      agd_first_BM = agd_last_BM = newagd;
    }
  else
    {
      ASSERT_BM (agd_last_BM != NULL);
      agd_last_BM->agd_next = newagd;
      agd_last_BM = newagd;
      newagd->agd_next = NULL;
    }
  pthread_mutex_unlock (&ti_agendamtx_BM);
}                               /* end agenda_defer_after_gc_BM */



void
agenda_notify_BM (void)
{
  pthread_cond_broadcast (&ti_agendacond_BM);
}                               // end agenda_notify_BM


static bool agenda_internal_remove_tasklet_BM (objectval_tyBM * taskob);
bool
agenda_internal_remove_tasklet_BM (objectval_tyBM * taskob)
{
  // caller has locked the ti_agendamtx_BM
  if (!isobject_BM ((value_tyBM) taskob))
    return false;
#define REMOVEPRIOTASKHSET_BM(Thset) do  {		\
     if (Thset						\
	 && hashsetobj_contains_BM (Thset, taskob)) {	\
       Thset = hashsetobj_remove_BM (Thset, taskob);	\
       return true;					\
     }							\
   } while(0)
  REMOVEPRIOTASKHSET_BM (ti_veryhigh_taskhset_BM);
  REMOVEPRIOTASKHSET_BM (ti_high_taskhset_BM);
  REMOVEPRIOTASKHSET_BM (ti_normal_taskhset_BM);
  REMOVEPRIOTASKHSET_BM (ti_low_taskhset_BM);
  REMOVEPRIOTASKHSET_BM (ti_verylow_taskhset_BM);
#undef REMOVEPRIOTASKHSET_BM
  return false;
}                               /* end agenda_internal_remove_tasklet_BM */

void
agenda_add_very_high_priority_tasklet_BM (objectval_tyBM * taskob)
{
  if (!isobject_BM ((value_tyBM) taskob))
    return;
  pthread_mutex_lock (&ti_agendamtx_BM);
  agenda_internal_remove_tasklet_BM (taskob);
  ti_veryhigh_taskhset_BM =
    hashsetobj_add_BM (ti_veryhigh_taskhset_BM, taskob);
  pthread_mutex_unlock (&ti_agendamtx_BM);
  pthread_cond_broadcast (&ti_agendacond_BM);
}                               /* end agenda_add_very_high_priority_tasklet_BM */

void
agenda_add_high_priority_tasklet_BM (objectval_tyBM * taskob)
{
  if (!isobject_BM ((value_tyBM) taskob))
    return;
  pthread_mutex_lock (&ti_agendamtx_BM);
  agenda_internal_remove_tasklet_BM (taskob);
  ti_high_taskhset_BM = hashsetobj_add_BM (ti_high_taskhset_BM, taskob);
  pthread_mutex_unlock (&ti_agendamtx_BM);
  pthread_cond_broadcast (&ti_agendacond_BM);
}                               /* end agenda_add_high_priority_tasklet_BM */

void
agenda_add_normal_priority_tasklet_BM (objectval_tyBM * taskob)
{
  if (!isobject_BM ((value_tyBM) taskob))
    return;
  pthread_mutex_lock (&ti_agendamtx_BM);
  agenda_internal_remove_tasklet_BM (taskob);
  ti_normal_taskhset_BM = hashsetobj_add_BM (ti_normal_taskhset_BM, taskob);
  pthread_mutex_unlock (&ti_agendamtx_BM);
  pthread_cond_broadcast (&ti_agendacond_BM);
}                               /* end agenda_add_normal_priority_tasklet_BM */

void
agenda_add_low_priority_tasklet_BM (objectval_tyBM * taskob)
{
  if (!isobject_BM ((value_tyBM) taskob))
    return;
  pthread_mutex_lock (&ti_agendamtx_BM);
  agenda_internal_remove_tasklet_BM (taskob);
  ti_low_taskhset_BM = hashsetobj_add_BM (ti_low_taskhset_BM, taskob);
  pthread_mutex_unlock (&ti_agendamtx_BM);
  pthread_cond_broadcast (&ti_agendacond_BM);
}                               /* end agenda_add_low_priority_tasklet_BM */

void
agenda_add_very_low_priority_tasklet_BM (objectval_tyBM * taskob)
{
  if (!isobject_BM ((value_tyBM) taskob))
    return;
  pthread_mutex_lock (&ti_agendamtx_BM);
  agenda_internal_remove_tasklet_BM (taskob);
  ti_verylow_taskhset_BM = hashsetobj_add_BM (ti_verylow_taskhset_BM, taskob);
  pthread_mutex_unlock (&ti_agendamtx_BM);
  pthread_cond_broadcast (&ti_agendacond_BM);
}                               /* end agenda_add_low_priority_tasklet_BM */

bool
agenda_remove_tasklet_BM (objectval_tyBM * taskob)
{
  if (!isobject_BM ((value_tyBM) taskob))
    return false;
  bool r = false;
  pthread_mutex_lock (&ti_agendamtx_BM);
  r = agenda_internal_remove_tasklet_BM (taskob);
  pthread_mutex_unlock (&ti_agendamtx_BM);
  pthread_cond_broadcast (&ti_agendacond_BM);
  return r;
}                               /* end agenda_remove_tasklet_BM */

long
agenda_get_counts_BM (long *pveryhigh, long *phigh, long *pnormal, long *plow,
                      long *pverylow)
{
  long totcnt = 0;
  pthread_mutex_lock (&ti_agendamtx_BM);
  {
    long veryhighcnt = hashsetobj_cardinal_BM (ti_veryhigh_taskhset_BM);
    if (pveryhigh)
      *pveryhigh = veryhighcnt;
    totcnt += veryhighcnt;
  }
  {
    long highcnt = hashsetobj_cardinal_BM (ti_high_taskhset_BM);
    if (phigh)
      *phigh = highcnt;
    totcnt += highcnt;
  }
  {
    long normalcnt = hashsetobj_cardinal_BM (ti_normal_taskhset_BM);
    if (pnormal)
      *pnormal = normalcnt;
    totcnt += normalcnt;
  }
  {
    long lowcnt = hashsetobj_cardinal_BM (ti_low_taskhset_BM);
    if (plow)
      *plow = lowcnt;
    totcnt += lowcnt;
  }
  {
    long verylowcnt = hashsetobj_cardinal_BM (ti_verylow_taskhset_BM);
    if (pverylow)
      *pverylow = verylowcnt;
    totcnt += verylowcnt;
  }
  pthread_mutex_unlock (&ti_agendamtx_BM);
  return totcnt;
}                               /* end agenda_get_counts_BM */

long
agenda_get_sets_BM (value_tyBM * pveryhighset,
                    value_tyBM * phighset, value_tyBM * pnormalset,
                    value_tyBM * plowset, value_tyBM * pverylowset)
{
  long totcnt = 0;
  pthread_mutex_lock (&ti_agendamtx_BM);
  {
    long veryhighcnt = hashsetobj_cardinal_BM (ti_veryhigh_taskhset_BM);
    if (pveryhighset)
      *pveryhighset =
        (value_tyBM) hashsetobj_to_set_BM (ti_veryhigh_taskhset_BM);;
    totcnt += veryhighcnt;
  }
  {
    long highcnt = hashsetobj_cardinal_BM (ti_high_taskhset_BM);
    if (phighset)
      *phighset = (value_tyBM) hashsetobj_to_set_BM (ti_high_taskhset_BM);
    totcnt += highcnt;
  }
  {
    long normalcnt = hashsetobj_cardinal_BM (ti_normal_taskhset_BM);
    if (pnormalset)
      *pnormalset = (value_tyBM) hashsetobj_to_set_BM (ti_normal_taskhset_BM);
    totcnt += normalcnt;
  }
  {
    long lowcnt = hashsetobj_cardinal_BM (ti_low_taskhset_BM);
    if (plowset)
      *plowset = (value_tyBM) hashsetobj_to_set_BM (ti_low_taskhset_BM);
    totcnt += lowcnt;
  }
  {
    long verylowcnt = hashsetobj_cardinal_BM (ti_verylow_taskhset_BM);
    if (pverylowset)
      *pverylowset =
        (value_tyBM) hashsetobj_to_set_BM (ti_verylow_taskhset_BM);
    totcnt += verylowcnt;
  }
  pthread_mutex_unlock (&ti_agendamtx_BM);
  return totcnt;
}                               /* end agenda_get_sets_BM */

void
run_agenda_internal_tasklet_BM (objectval_tyBM * obtk,
                                struct failurelockset_stBM *flh)
{
  if (!isobject_BM (obtk))      // should never happen
    FATAL_BM ("bad tasklet object @%p", obtk);
  ASSERT_BM (flh != NULL);
  LOCALFRAME_BM ( /*prev: */ NULL, /*descr: */ NULL,
                 objectval_tyBM * obtk;
                 value_tyBM failres;);
  _.obtk = obtk;
  curfailurehandle_BM = NULL;
  objlock_BM (_.obtk);
  volatile int failcod = 0;
  struct failurehandler_stBM fh =       //
  {
    .pA = {.htyp = typayl_FailureHandler_BM},
    .failh_magic = FAILUREHANDLEMAGIC_BM,
    .failh_lockset = NULL,
    .failh_reason = NULL,
    .failh_jmpbuf = {}
  };
  fh.failh_lockset = flh;
  curfailurehandle_BM = &fh;
  failcod = setjmp (fh.failh_jmpbuf);
  if (!failcod)
    {
      (void) send0_BM (_.obtk, BMP_run_tasklet, CURFRAME_BM);
    }
  else
    {
      char curidbuf[32];
      memset (curidbuf, 0, sizeof (curidbuf));
      idtocbuf32_BM (objid_BM (_.obtk), curidbuf);
      _.failres = fh.failh_reason;
      const char *failmsg = debug_outstr_value_BM (_.failres, CURFRAME_BM,
                                                   0);
      fprintf (stderr, "tasklet %s failed code#%d reason %s\n", curidbuf,
               failcod, failmsg);
    };
  curfailurehandle_BM = NULL;
  objunlock_BM (_.obtk);
}                               /* end run_agenda_internal_tasklet_BM */

void
defer_module_load_BM (objectval_tyBM * modulobarg, const closure_tyBM * postclosarg,    //
                      value_tyBM arg1, value_tyBM arg2, value_tyBM arg3,        //
                      struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_defer_module_load = BMK_4fBgmgx2KrN_3PCZfdnI1CJ;
  objectval_tyBM *k_plain_temporary_module = BMK_1oEp0eAAyFN_4lsobepyr1T;
  LOCALFRAME_BM (stkf, /*descr: */ k_defer_module_load,
                 objectval_tyBM * modulob;      //
                 const closure_tyBM * postclos;
                 value_tyBM arg1v;      //
                 value_tyBM arg2v;      //
                 value_tyBM arg3v;      //
                 objectval_tyBM * curob;        //
                 objectval_tyBM * routob;       //
                 value_tyBM causev;
                 value_tyBM errorv;
    );
  extern void deferred_do_module_load_BM (value_tyBM * valarr, unsigned nbval, void *data);     /* in misc_BM.cc */
  _.modulob = objectcast_BM (modulobarg);
  _.postclos = closurecast_BM ((value_tyBM) postclosarg);
  _.arg1v = arg1;
  _.arg2v = arg2;
  _.arg3v = arg3;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  if (!_.modulob)
    FAILHERE (BMP_load_module);
  if (!isclosure_BM ((value_tyBM) _.postclos))
    FAILHERE (BMP_closure);
  bool modulistemporary =
    (objectisinstance_BM (_.modulob, k_plain_temporary_module));
  char modulidbuf[32];
  memset (modulidbuf, 0, sizeof (modulidbuf));
  idtocbuf32_BM (objid_BM (_.modulob), modulidbuf);
  DBGPRINTF_BM
    ("defer_module_load_BM start modulob %s %s postclos %s arg1 %s arg2 %s arg3 %s",
     objectdbg_BM (_.modulob), modulistemporary ? "temporary" : "persistent",
     debug_outstr_value_BM ((value_tyBM) _.postclos, CURFRAME_BM, 0),
     debug_outstr_value_BM (_.arg1v, CURFRAME_BM, 0),
     debug_outstr_value_BM (_.arg2v, CURFRAME_BM, 0),
     debug_outstr_value_BM (_.arg3v, CURFRAME_BM, 0));
  // test that the module file exists
  char *modulpath = NULL;
  if (modulistemporary)
    asprintf (&modulpath, "%s/" MODULEDIR_BM "/" TEMPMODULEPREFIX_BM "%s.so",
              bismon_directory, modulidbuf);
  else
    asprintf (&modulpath, "%s/" MODULEDIR_BM "/" MODULEPREFIX_BM "%s.so",
              bismon_directory, modulidbuf);
  if (!modulpath)
    FATAL_BM ("failed to make modulpath for %s", modulidbuf);
  FILE *binmodf = fopen (modulpath, "r");
  if (!binmodf)
    {
      fprintf (stderr, "failed to read binary %s module %s for %s: %m\n",
               modulpath, modulistemporary ? "temporary" : "persistent",
               objectdbg_BM (_.modulob));
      FAILHERE (makenode1_BM
                (BMP_load_module, (value_tyBM) makestring_BM (modulpath)));
    }
  char eident[EI_NIDENT];
  memset (eident, 0, sizeof (eident));
  int nbread = fread (eident, EI_NIDENT, 1, binmodf);
  if (nbread < 1
      || eident[0] != ELFMAG0 || eident[1] != ELFMAG1 || eident[2] != ELFMAG2
      || eident[3] != ELFMAG3)
    {
      DBGPRINTF_BM ("defer_module_load bad ELF ident %x %x %x %x (want %x %x %x %x) nbread %d for modulpath %s modulob %s", eident[0], eident[1], eident[2], eident[3], //
                    ELFMAG0, ELFMAG1, ELFMAG2, ELFMAG3, //
                    nbread, modulpath, objectdbg_BM (_.modulob));
      fprintf (stderr, "module binary %s for %s is not ELF.\n",
               modulpath, objectdbg_BM (_.modulob));
      fclose (binmodf);
      FAILHERE (makenode1_BM (BMP_load_module,
                              (value_tyBM) makestring_BM (modulpath)));
    };
  fclose (binmodf);
  {
    value_tyBM varr[8] = { };
    varr[0] = _.modulob;
    varr[1] = (value_tyBM) _.postclos;
    varr[2] = _.arg1v;
    varr[3] = _.arg2v;
    varr[4] = _.arg3v;
    DBGPRINTF_BM
      ("defer_module_load defer after gc modulob %s, postclos %s, arg1 %s, arg2 %s, arg3 %s",
       objectdbg_BM (_.modulob),
       debug_outstr_value_BM ((value_tyBM) _.postclos, CURFRAME_BM, 0),
       debug_outstr_value_BM (_.arg1v, CURFRAME_BM, 0),
       debug_outstr_value_BM (_.arg2v, CURFRAME_BM, 0),
       debug_outstr_value_BM (_.arg3v, CURFRAME_BM, 0));
    agenda_defer_after_gc_BM (deferred_do_module_load_BM, varr, 5, modulpath);
  }
  atomic_store (&want_garbage_collection_BM, true);
  agenda_notify_BM ();
  DBGPRINTF_BM ("defer_module_load_BM end modulob %s",
                objectdbg_BM (_.modulob));
  return;
failure:
#undef FAILHERE
  DBGPRINTF_BM ("defer_module_load failin failin=%d causev=%s modulob=%s/%s arg1=%s arg2=%s arg3=%s", failin, debug_outstr_value_BM (_.causev, CURFRAME_BM, 0), objectdbg_BM (_.modulob), modulidbuf,   //
                debug_outstr_value_BM (_.arg1v, CURFRAME_BM, 0),        //
                debug_outstr_value_BM (_.arg2v, CURFRAME_BM, 0),        //
                debug_outstr_value_BM (_.arg3v, CURFRAME_BM, 0));
  _.errorv =
    makenode6_BM (k_defer_module_load, _.modulob, (value_tyBM) _.postclos,
                  _.arg1v, _.arg2v, _.arg3v, _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);

}                               /* end defer_module_load_BM */
