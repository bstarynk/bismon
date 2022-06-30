// file agenda_BM.c
// SPDX-License-Identifier: GPL-3.0-or-later
/***
    BISMON 
    Copyright © 2018 - 2022 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
    contributed by Basile Starynkevitch (working at CEA, LIST, France)
    <basile@starynkevitch.net> or <basile.starynkevitch@cea.fr>

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




#define POSTPONE_MAGIC_BM 0x18e6b7a9    /*417773481 */
struct agenda_postpone_stBM
{
  unsigned agpo_magic;          /*always  POSTPONE_MAGIC_BM */
  struct agenda_postpone_stBM *agpo_next;
  struct agenda_postpone_stBM *agpo_prev;
  double agpo_timestamp;
  value_tyBM agpo_todo;         /* closure to apply or selector to send */
  value_tyBM agpo_recv;         /* reciever, when sending */
  value_tyBM agpo_arg1;
  value_tyBM agpo_arg2;
  value_tyBM agpo_arg3;
};                              /* end of agenda_postpone_stBM */

/// under ti_agendamtx_BM mutex lock!!
static struct agenda_postpone_stBM *agpostpone_first_BM;
static struct agenda_postpone_stBM *agpostpone_last_BM;





static void *run_agendaworker_BM (void *);
static void run_agenda_internal_tasklet_BM (objectval_tyBM * obtk,
                                            struct failurelockset_stBM *flh);
static objectval_tyBM *choose_task_internal_agenda_BM (void);
static struct hashsetobj_stBM *maybe_reorganize_taskhshet_agenda_BM     //
  (struct hashsetobj_stBM *tkhset);

bool
agenda_need_gc_BM (void)
{
  return atomic_load (&ti_needgc_BM);
}                               /* end agenda_need_gc_BM */


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



void
agenda_wait_gc_BM (void)
{
  struct timespec ts = { 0, 0 };
  get_realtimespec_delayedms_BM (&ts, GCWAITMILLISECONDS_BM);
  NONPRINTF_BM
    ("agenda_wait_gc_BM tid#%ld before timedwait elapsed %.3f s",
     (long) gettid_BM (), elapsedtime_BM ());
  pthread_mutex_lock (&ti_agendamtx_BM);
  pthread_cond_timedwait (&ti_agendacond_BM, &ti_agendamtx_BM, &ts);
  pthread_mutex_unlock (&ti_agendamtx_BM);
}                               /* end agenda_wait_gc_BM */



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



extern double taskletcputime_BM (void) __attribute__((optimize ("-O3")));
extern double taskletelapsedtime_BM (void) __attribute__((optimize ("-O3")));


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
  usleep (2000 + 100 * nbjobs);
  for (int ix = 1; ix <= nbjobs; ix++)
    {
      usleep (333);
      pthread_create (&ti_array_BM[ix].ti_pthread, &at,
                      run_agendaworker_BM, (void *) (intptr_t) ix);
    }
  usleep (100);
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
  usleep (50);
  pthread_cond_broadcast (&ti_agendacond_BM);
  usleep (1000);
  do
    {
      usleep (100);
      pthread_mutex_lock (&ti_agendamtx_BM);
      struct timespec ts = { 0, 0 };
      get_realtimespec_delayedms_BM (&ts, STOPWAITMILLISECONDS_BM);
      NONPRINTF_BM ("stop_agenda_work_threads tid#%ld", (long) gettid_BM ());
      pthread_cond_timedwait (&ti_agendacond_BM, &ti_agendamtx_BM, &ts);
      pthread_mutex_unlock (&ti_agendamtx_BM);
    }
  while (atomic_load (&ti_countendedthreads_BM) < nbwth);
}                               /* end stop_agenda_work_threads_BM */


// agenda_suspend_for_gc_BM is called from full_garbage_collection_BM
void
agenda_suspend_for_gc_BM (void)
{
  ASSERT_BM (curthreadinfo_BM == NULL);
  atomic_store (&ti_needgc_BM, true);
  pthread_cond_broadcast (&ti_agendacond_BM);
  bool alldoinggc = false;
  int nbwth = ti_nbworkers_BM;
  long loopcnt = 0;
  DBGPRINTF_BM ("agenda_suspend_for_gc_BM nwth=%d", nbwth);
  while (!alldoinggc)
    {
      alldoinggc = false;
      int wix = 0;
      loopcnt++;
      DBGPRINTF_BM
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
  DBGPRINTF_BM ("agenda_suspend_for_gc_BM done");
}                               /* end agenda_suspend_for_gc_BM */

void
agenda_continue_after_gc_BM (void)
{
  ASSERT_BM (curthreadinfo_BM == NULL);
  int nbwth = ti_nbworkers_BM;
  DBGPRINTF_BM ("agenda_continue_after_gc tid#%ld elapsed %.3f s",
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
  usleep (5);
  DBGPRINTF_BM ("agenda_continue_after_gc end tid#%ld elapsed %.3f s",
                (long) gettid_BM (), elapsedtime_BM ());
}                               /* end agenda_continue_after_gc_BM */

void
agenda_run_deferred_after_gc_BM (void)
{
  LOCALFRAME_BM (NULL, NULL, value_tyBM curv);
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
      if (showdebugmsg_BM)
        {
          Dl_info di = { };
          if (dladdr (curagd->agd_rout, &di) && di.dli_sname)
            DBGBACKTRACEPRINTF_BM
              ("agenda_run_deferred_after_gc_BM rout %s @%p nbval#%d",
               di.dli_sname, (void *) curagd->agd_rout,
               (int) curagd->agd_nbval);
          else
            DBGBACKTRACEPRINTF_BM
              ("agenda_run_deferred_after_gc_BM rout@%p nbval#%d",
               (void *) curagd->agd_rout, (int) curagd->agd_nbval);
          for (int ix = 0; ix < (int) curagd->agd_nbval; ix++)
            {
              _.curv = curagd->agd_valarr[ix];
#warning perhaps dangerous DBGPRINTF_BM in agenda_run_deferred_after_gc_BM
              /// this might not be safe if GC happens inside
              DBGPRINTF_BM ("agenda_run_deferred_after_gc..val[%d]: %s",
                            ix, OUTSTRVALUE_BM (_.curv));
            }
        }
      (*curagd->agd_rout) (curagd->agd_valarr, curagd->agd_nbval,
                           curagd->agd_data);
      DBGPRINTF_BM ("agenda_run_deferred_after_gc done rout@%p\n",
                    (void *) curagd->agd_rout);
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
      WARNPRINTF_BM ("tasklet %s failed code#%d reason %s\n", curidbuf,
                     failcod, failmsg);
    };
  curfailurehandle_BM = NULL;
  objunlock_BM (_.obtk);
}                               /* end run_agenda_internal_tasklet_BM */


void
defer_module_dynload_BM (objectval_tyBM * modulobarg, const closure_tyBM * postclosarg, //
                         value_tyBM arg1, value_tyBM arg2, value_tyBM arg3,     //
                         struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_defer_module_dynload = BMK_4fBgmgx2KrN_3PCZfdnI1CJ;
  objectval_tyBM *k_plain_temporary_module = BMK_1oEp0eAAyFN_4lsobepyr1T;
  LOCALFRAME_BM (stkf, /*descr: */ k_defer_module_dynload,
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
  extern void deferred_do_module_dynload_BM (value_tyBM * valarr, unsigned nbval, void *data);  /* in misc_BM.cc */
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
  DBGBACKTRACEPRINTF_BM
    ("defer_module_dynload_BM start modulob %s %s postclos %s arg1 %s arg2 %s arg3 %s",
     objectdbg_BM (_.modulob), modulistemporary ? "temporary" : "persistent",
     OUTSTRVALUE_BM ((value_tyBM) _.postclos),
     OUTSTRVALUE_BM (_.arg1v),
     OUTSTRVALUE_BM (_.arg2v), OUTSTRVALUE_BM (_.arg3v));
  // test that the module file exists
  char *progmodulpath = NULL;   // the asprintf-ed binary module in bismon_directory
  char *curmodulpath = NULL;    // the asprintf-ed binary module in current directory
  char *modulpath = NULL;
  {
    int a = -1;
    if (modulistemporary)
      a = asprintf (&progmodulpath,
                    "%s/" MODULEBINDIR_BM "/" TEMPMODULEPREFIX_BM "%s.so",
                    bismon_directory, modulidbuf);
    else
      a =
        asprintf (&progmodulpath,
                  "%s/" MODULEBINDIR_BM "/" MODULEPREFIX_BM "%s.so",
                  bismon_directory, modulidbuf);
    if (a < 0 || !progmodulpath)
      FATAL_BM ("failed to make progmodulpath for %s", modulidbuf);
  }
  {
    int a = -1;
    if (modulistemporary)
      a = asprintf (&curmodulpath,
                    MODULEBINDIR_BM "/" TEMPMODULEPREFIX_BM "%s.so",
                    modulidbuf);
    else
      a =
        asprintf (&curmodulpath,
                  MODULEBINDIR_BM "/" MODULEPREFIX_BM "%s.so", modulidbuf);
    if (a < 0 || !curmodulpath)
      FATAL_BM ("failed to make curmodulpath for %s", modulidbuf);
  }
  if (!access (curmodulpath, F_OK))
    {
      modulpath = curmodulpath;
      free (progmodulpath), progmodulpath = NULL;
    }
  else if (!access (progmodulpath, F_OK))
    {
      modulpath = progmodulpath;
      free (curmodulpath), curmodulpath = NULL;
    };
  FILE *binmodf = modulpath ? fopen (modulpath, "r") : NULL;
  if (!binmodf)
    {
      WARNPRINTF_BM ("failed to read binary %s module %s for %s: %m\n",
                     modulpath ? : "*missing*",
                     modulistemporary ? "temporary" : "persistent",
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
      DBGPRINTF_BM ("defer_module_dynload bad ELF ident %x %x %x %x (want %x %x %x %x) nbread %d for modulpath %s modulob %s",  //
                    eident[0], eident[1], eident[2], eident[3], //
                    ELFMAG0, ELFMAG1, ELFMAG2, ELFMAG3, //
                    nbread, modulpath, objectdbg_BM (_.modulob));
      WARNPRINTF_BM ("module binary %s for %s is not ELF.\n",
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
    DBGBACKTRACEPRINTF_BM
      ("defer_module_dynload defer after gc modulob %s, postclos %s, arg1 %s, arg2 %s, arg3 %s",
       objectdbg_BM (_.modulob),
       OUTSTRVALUE_BM ((value_tyBM) _.postclos),
       OUTSTRVALUE_BM (_.arg1v),
       OUTSTRVALUE_BM (_.arg2v), OUTSTRVALUE_BM (_.arg3v));
    agenda_defer_after_gc_BM (deferred_do_module_dynload_BM, varr, 5,
                              modulpath);
  }
  request_delayed_garbage_collection_BM ();
  DBGPRINTF_BM ("defer_module_dynload_BM end modulob %s",
                objectdbg_BM (_.modulob));
  return;
failure:
#undef FAILHERE
  DBGPRINTF_BM ("defer_module_dynload failin failin=%d causev=%s modulob=%s/%s arg1=%s arg2=%s arg3=%s",        //
                failin, OUTSTRVALUE_BM (_.causev),      //
                objectdbg_BM (_.modulob), modulidbuf,   //
                OUTSTRVALUE_BM (_.arg1v),       //
                OUTSTRVALUE_BM (_.arg2v),       //
                OUTSTRVALUE_BM (_.arg3v));
  _.errorv = (value_tyBM)
    makenode6_BM (k_defer_module_dynload, _.modulob, (value_tyBM) _.postclos,
                  _.arg1v, _.arg2v, _.arg3v, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);

}                               /* end defer_module_dynload_BM */



////////////////////////////////////////////////////////////////


static void enqueue_postpone_bm (struct agenda_postpone_stBM *apo,
                                 struct stackframe_stBM *stkf);

/// potstponed things to do
#define POSTPONED_MINI_DELAY_MILLISEC_BM 512

void
do_postpone_defer_apply3_BM (int delayms, value_tyBM closarg,
                             value_tyBM arg1arg, value_tyBM arg2arg,
                             value_tyBM arg3arg, struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_do_postpone_defer_apply3 = BMK_60MoTMcUOQS_5XuFzMzNDN0;
  LOCALFRAME_BM ( /*prev stackf: */ stkf,       /*descr: */
                 k_do_postpone_defer_apply3, value_tyBM closv;  // closure
                 value_tyBM arg1v;      // first argument
                 value_tyBM arg2v;      // second argument
                 value_tyBM arg3v;      // third argument
                 value_tyBM tmpv;
    );
  _.closv = closarg;
  _.arg1v = arg1arg;
  _.arg2v = arg2arg;
  _.arg3v = arg3arg;
  if (delayms < POSTPONED_MINI_DELAY_MILLISEC_BM)
    delayms = POSTPONED_MINI_DELAY_MILLISEC_BM;
  if (!isclosure_BM (_.closv))
    {
      WARNPRINTF_BM
        ("do_postpone_defer_apply3 delayms#%d called with bad closure %s arg1:%s arg2:%s arg3:%s",
         delayms, OUTSTRVALUE_BM (_.closv), OUTSTRVALUE_BM (_.arg1v),
         OUTSTRVALUE_BM (_.arg2v), OUTSTRVALUE_BM (_.arg3v));
      WEAKASSERTWARN_BM ("do_postpone_defer_apply3 bad closure" && false);
      return;
    }
  struct agenda_postpone_stBM *apo =
    calloc (sizeof (struct agenda_postpone_stBM), 1);
  if (!apo)
    FATAL_BM ("failed to calloc in do_postpone_defer_apply3");
  apo->agpo_magic = POSTPONE_MAGIC_BM;
  apo->agpo_next = NULL;
  apo->agpo_prev = NULL;
  apo->agpo_timestamp = (double) delayms + elapsedtime_BM ();
  apo->agpo_todo = _.closv;
  apo->agpo_recv = NULL;
  apo->agpo_arg1 = _.arg1v;
  apo->agpo_arg2 = _.arg2v;
  apo->agpo_arg3 = _.arg3v;
  enqueue_postpone_bm (apo, CURFRAME_BM);
}                               /* end do_postpone_defer_apply3_BM */



// defer a message send, running in the main thread
void
do_postpone_defer_send3_BM (int delayms, value_tyBM recvarg,
                            objectval_tyBM * obselarg, value_tyBM arg1arg,
                            value_tyBM arg2arg, value_tyBM arg3arg,
                            struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_do_postpone_defer_send3 = BMK_8fmRLMCFhgf_0owpXXFFJZE;
  LOCALFRAME_BM ( /*prev stackf: */ stkf,
                 /*descr: */ k_do_postpone_defer_send3,
                 //
                 value_tyBM recv;       // reciever
                 objectval_tyBM * obsel;        // selector
                 value_tyBM arg1v;      // first argument
                 value_tyBM arg2v;      // second argument
                 value_tyBM arg3v;      // third argument
                 value_tyBM tmpv;
    );
  _.recv = recvarg;
  _.obsel = obselarg;
  _.arg1v = arg1arg;
  _.arg2v = arg2arg;
  _.arg3v = arg3arg;
  if (delayms < POSTPONED_MINI_DELAY_MILLISEC_BM)
    delayms = POSTPONED_MINI_DELAY_MILLISEC_BM;
  // we don't handle the case when the method is installed or removed
  // after the call here!
  if (!valfindmethod_BM (_.recv, _.obsel))
    {
      WARNPRINTF_BM
        ("do_postpone_defer_send3 delayms#%d wrongly called recv=%s obsel:%s arg1:%s arg2:%s arg3:%s",
         delayms, OUTSTRVALUE_BM (_.recv), objectdbg_BM (_.obsel),
         OUTSTRVALUE_BM (_.arg1v), OUTSTRVALUE_BM (_.arg2v),
         OUTSTRVALUE_BM (_.arg3v));
      WEAKASSERTWARN_BM ("do_postpone_defer_send3 wrongly called" && false);
      return;
    }
  WARNPRINTF_BM
    ("maybe unimplemented do_postpone_defer_send3_BM delayms#%d recv=%s obsel=%s arg1v=%s arg2v=%s arg3v=%s",
     delayms, OUTSTRVALUE_BM (_.recv), objectdbg_BM (_.obsel),
     OUTSTRVALUE_BM (_.arg1v), OUTSTRVALUE_BM (_.arg2v),
     OUTSTRVALUE_BM (_.arg3v));
  struct agenda_postpone_stBM *apo =
    calloc (sizeof (struct agenda_postpone_stBM), 1);
  if (!apo)
    FATAL_BM ("failed to calloc in do_postpone_defer_apply3");
  apo->agpo_magic = POSTPONE_MAGIC_BM;
  apo->agpo_next = NULL;
  apo->agpo_prev = NULL;
  apo->agpo_timestamp = (double) delayms + elapsedtime_BM ();
  apo->agpo_todo = _.obsel;
  apo->agpo_recv = _.recv;
  apo->agpo_arg1 = _.arg1v;
  apo->agpo_arg2 = _.arg2v;
  apo->agpo_arg3 = _.arg3v;
  enqueue_postpone_bm (apo, CURFRAME_BM);
}                               /* end do_postpone_defer_send3_BM */



void
enqueue_postpone_bm (struct agenda_postpone_stBM *apo,
                     struct stackframe_stBM *stkf)
{
  ASSERT_BM (apo != NULL && apo->agpo_magic == POSTPONE_MAGIC_BM);
  ASSERT_BM (stkf != NULL);
  ASSERT_BM (apo->agpo_prev == NULL && apo->agpo_next == NULL);
  pthread_mutex_lock (&ti_agendamtx_BM);
  if (UNLIKELY_BM (agpostpone_first_BM == NULL))
    {
      ASSERT_BM (agpostpone_last_BM == NULL);
      agpostpone_first_BM = agpostpone_last_BM = apo;
    }
  else
    {
      ASSERT_BM (agpostpone_first_BM->agpo_magic == POSTPONE_MAGIC_BM);
      double timsta = apo->agpo_timestamp;
      if (timsta < agpostpone_first_BM->agpo_timestamp)
        {
          ASSERT_BM (agpostpone_first_BM->agpo_prev == NULL);
          agpostpone_first_BM->agpo_prev = apo;
          apo->agpo_next = agpostpone_first_BM;
          apo->agpo_prev = NULL;
          agpostpone_first_BM = apo;
        }
      else
        for (struct agenda_postpone_stBM * curapo = agpostpone_first_BM;
             curapo != NULL; curapo = curapo->agpo_next)
          {
            ASSERT_BM (curapo->agpo_magic == POSTPONE_MAGIC_BM);
            struct agenda_postpone_stBM *nextapo = curapo->agpo_next;
            ASSERT_BM (nextapo == NULL
                       || nextapo->agpo_magic == POSTPONE_MAGIC_BM);
            struct agenda_postpone_stBM *prevapo = curapo->agpo_prev;
            ASSERT_BM (prevapo == NULL
                       || prevapo->agpo_magic == POSTPONE_MAGIC_BM);
            double timnext = nextapo ? nextapo->agpo_timestamp : +INFINITY;
            if (timsta >= curapo->agpo_timestamp && timsta < timnext)
              {
                curapo->agpo_next = apo;
                apo->agpo_prev = curapo;
                apo->agpo_next = nextapo;
                if (nextapo != NULL)
                  nextapo->agpo_prev = apo;
                else
                  {
                    ASSERT_BM (curapo == agpostpone_last_BM);
                    agpostpone_last_BM = apo;
                  }
                break;
              }
          }
    }
  ASSERT_BM (agpostpone_first_BM != NULL
             && agpostpone_first_BM->agpo_magic == POSTPONE_MAGIC_BM);
  double nextimstamp = agpostpone_first_BM->agpo_timestamp;
  pthread_mutex_unlock (&ti_agendamtx_BM);
  pthread_cond_broadcast (&ti_agendacond_BM);
}                               /* end enqueue_postpone_bm */



value_tyBM
get_newest_postpone_BM (double *pdelay, struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_get_newest_postpone = BMK_5CLivLxNfck_3LvC9xLO1oc;
  objectval_tyBM *k_postponed_apply = BMK_6kxUF3055z5_3pRMhBvXESe;
  objectval_tyBM *k_postponed_send = BMK_0poxpCxWsPO_8Uy4OL9eziR;
  LOCALFRAME_BM ( /*prev stackf: */ stkf,
                 /*descr: */ k_get_newest_postpone,
                 //
                 value_tyBM recv;       // reciever
                 value_tyBM todov;      //
                 value_tyBM arg1v;      // first argument
                 value_tyBM arg2v;      // second argument
                 value_tyBM arg3v;      // third argument
                 value_tyBM tmpv;       //
                 value_tyBM resv;       //
    );
  bool missing = true;
  if (pdelay)
    *pdelay = 0.0;
  _.resv = NULL;
  pthread_mutex_lock (&ti_agendamtx_BM);
  if (UNLIKELY_BM (agpostpone_first_BM == NULL))
    {
      ASSERT_BM (agpostpone_last_BM == NULL);
      goto end;
    };
  ASSERT_BM (agpostpone_first_BM->agpo_magic == POSTPONE_MAGIC_BM);
  double ts = agpostpone_first_BM->agpo_timestamp;
  missing = false;
  _.todov = agpostpone_first_BM->agpo_todo;
  _.recv = agpostpone_first_BM->agpo_recv;
  _.arg1v = agpostpone_first_BM->agpo_arg1;
  _.arg2v = agpostpone_first_BM->agpo_arg2;
  _.arg3v = agpostpone_first_BM->agpo_arg3;
end:
  pthread_mutex_unlock (&ti_agendamtx_BM);
  if (!missing)
    {
      DBGPRINTF_BM ("get_newest_postpone_BM todo %s, recv %s,\n"
                    ".. arg1=%s, arg2=%s, arg3=%s",
                    OUTSTRVALUE_BM (_.todov),
                    OUTSTRVALUE_BM (_.recv),
                    OUTSTRVALUE_BM (_.arg1v),
                    OUTSTRVALUE_BM (_.arg2v), OUTSTRVALUE_BM (_.arg3v));
      if (isclosure_BM (_.todov))
        {                       // postponed apply of todov closure
          ASSERT_BM (_.recv == NULL);
          _.resv = (value_tyBM)
            makenode4_BM (k_postponed_apply, _.todov, _.arg1v, _.arg2v,
                          _.arg3v);
        }
      else if (isobject_BM (_.todov))
        {                       // postponed send of todov selector
          _.resv = (value_tyBM)
            makenode5_BM (k_postponed_send, _.recv, _.todov, _.arg1v, _.arg2v,
                          _.arg3v);
        }
      else
        {                       // should never happen
          FATAL_BM ("get_newest_postpone_BM bad todo %s, recv %s,\n"
                    ".. arg1=%s, arg2=%s, arg3=%s",
                    OUTSTRVALUE_BM (_.todov),
                    OUTSTRVALUE_BM (_.recv),
                    OUTSTRVALUE_BM (_.arg1v),
                    OUTSTRVALUE_BM (_.arg2v), OUTSTRVALUE_BM (_.arg3v));
        };
      if (pdelay != NULL)
        *pdelay = ts;
    }
  return _.resv;
}                               /* end of get_newest_postpone_BM */



value_tyBM
pop_newest_postpone_BM (double *ptimestamp, struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_pop_newest_postpone = BMK_0zcVE3vaq9X_5ThchgCp23w;
  objectval_tyBM *k_postponed_apply = BMK_6kxUF3055z5_3pRMhBvXESe;
  objectval_tyBM *k_postponed_send = BMK_0poxpCxWsPO_8Uy4OL9eziR;
  LOCALFRAME_BM ( /*prev stackf: */ stkf,
                 /*descr: */ k_pop_newest_postpone,
                 //
                 value_tyBM recv;       // reciever
                 value_tyBM todov;      //
                 value_tyBM arg1v;      // first argument
                 value_tyBM arg2v;      // second argument
                 value_tyBM arg3v;      // third argument
                 value_tyBM tmpv;       //
                 value_tyBM resv;       //
    );
  bool missing = true;
  if (ptimestamp)
    *ptimestamp = 0.0;
  _.resv = NULL;
  pthread_mutex_lock (&ti_agendamtx_BM);
  if (UNLIKELY_BM (agpostpone_first_BM == NULL))
    {
      ASSERT_BM (agpostpone_last_BM == NULL);
      goto end;
    };
  ASSERT_BM (agpostpone_first_BM->agpo_magic == POSTPONE_MAGIC_BM);
  double ts = agpostpone_first_BM->agpo_timestamp;
  missing = false;
  _.todov = agpostpone_first_BM->agpo_todo;
  _.recv = agpostpone_first_BM->agpo_recv;
  _.arg1v = agpostpone_first_BM->agpo_arg1;
  _.arg2v = agpostpone_first_BM->agpo_arg2;
  _.arg3v = agpostpone_first_BM->agpo_arg3;
  if (agpostpone_first_BM == agpostpone_last_BM)
    {
      free (agpostpone_first_BM);
      agpostpone_first_BM = NULL;
      agpostpone_last_BM = NULL;
    }
  else
    {
      struct agenda_postpone_stBM *apo = agpostpone_first_BM;
      agpostpone_first_BM = apo->agpo_next;
      memset (apo, 0, sizeof (*apo));
      free (apo);
    }
end:
  pthread_mutex_unlock (&ti_agendamtx_BM);
  if (!missing)
    {
      DBGPRINTF_BM ("pop_newest_postpone_BM todo %s, recv %s,\n"
                    ".. arg1=%s, arg2=%s, arg3=%s",
                    OUTSTRVALUE_BM (_.todov),
                    OUTSTRVALUE_BM (_.recv),
                    OUTSTRVALUE_BM (_.arg1v),
                    OUTSTRVALUE_BM (_.arg2v), OUTSTRVALUE_BM (_.arg3v));
      if (isclosure_BM (_.todov))
        {                       // postponed apply of todov closure
          ASSERT_BM (_.recv == NULL);
          _.resv = (value_tyBM)
            makenode4_BM (k_postponed_apply, _.todov, _.arg1v, _.arg2v,
                          _.arg3v);
        }
      else if (isobject_BM (_.todov))
        {                       // postponed send of todov selector
          _.resv = (value_tyBM)
            makenode5_BM (k_postponed_send, _.recv, _.todov, _.arg1v, _.arg2v,
                          _.arg3v);
        }
      else
        {                       // should never happen
          FATAL_BM ("pop_newest_postpone_BM bad todo %s, recv %s,\n"
                    ".. arg1=%s, arg2=%s, arg3=%s",
                    OUTSTRVALUE_BM (_.todov),
                    OUTSTRVALUE_BM (_.recv),
                    OUTSTRVALUE_BM (_.arg1v),
                    OUTSTRVALUE_BM (_.arg2v), OUTSTRVALUE_BM (_.arg3v));
        };
      if (ptimestamp != NULL)
        *ptimestamp = ts;
    }
  return _.resv;
}                               /* end of pop_newest_postpone_BM */


double
timestamp_newest_postpone_BM (void)
{
  double timestamp = 0.0;
  pthread_mutex_lock (&ti_agendamtx_BM);
  if (LIKELY_BM (agpostpone_first_BM != NULL))
    {
      ASSERT_BM (agpostpone_first_BM->agpo_magic == POSTPONE_MAGIC_BM);
      timestamp = agpostpone_first_BM->agpo_timestamp;
    }
  pthread_mutex_unlock (&ti_agendamtx_BM);
  return timestamp;
}                               /* end timestamp_newest_pospone_BM */


value_tyBM
run_postponed_node_BM (value_tyBM nodarg, struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_run_postponed_node = BMK_3S8QZc90hhJ_7Ss6IRxe13m;
  objectval_tyBM *k_postponed_apply = BMK_6kxUF3055z5_3pRMhBvXESe;
  objectval_tyBM *k_postponed_send = BMK_0poxpCxWsPO_8Uy4OL9eziR;
  LOCALFRAME_BM ( /*prev stackf: */ stkf,
                 /*descr: */ k_run_postponed_node,
                 //
                 value_tyBM nodv;       //
                 objectval_tyBM * connob;       //
                 value_tyBM recv;       // reciever
                 value_tyBM todov;      //
                 value_tyBM doclosv;    //
                 objectval_tyBM * obsel;        //
                 value_tyBM arg1v;      // first argument
                 value_tyBM arg2v;      // second argument
                 value_tyBM arg3v;      // third argument
                 value_tyBM tmpv;       //
                 value_tyBM resv;       //
    );
  _.nodv = nodarg;
  DBGPRINTF_BM ("run_postponed_node_BM start nodv=%s",
                OUTSTRVALUE_BM (_.nodv));
  if (!isnode_BM (_.nodv))
    LOCALRETURN_BM (NULL);
  _.connob = nodeconn_BM (_.nodv);
  unsigned nodw = nodewidth_BM (_.nodv);
  if (_.connob == k_postponed_apply && nodw == 4)
    {
      _.doclosv = nodenthson_BM (_.nodv, 0);
      _.arg1v = nodenthson_BM (_.nodv, 1);
      _.arg2v = nodenthson_BM (_.nodv, 2);
      _.arg3v = nodenthson_BM (_.nodv, 3);
      DBGPRINTF_BM
        ("run_postponed_node_BM apply doclosv=%s arg1v=%s arg2v=%s arg3v=%s",
         OUTSTRVALUE_BM (_.doclosv), OUTSTRVALUE_BM (_.arg1v),
         OUTSTRVALUE_BM (_.arg2v), OUTSTRVALUE_BM (_.arg3v));
      _.resv = apply3_BM (_.doclosv, CURFRAME_BM, _.arg1v, _.arg2v, _.arg3v);
      DBGPRINTF_BM
        ("run_postponed_node_BM applied doclosv=%s  arg1v=%s arg2v=%s arg3v=%s got resv=%s",
         OUTSTRVALUE_BM (_.doclosv), OUTSTRVALUE_BM (_.arg1v),
         OUTSTRVALUE_BM (_.arg2v), OUTSTRVALUE_BM (_.arg3v),
         OUTSTRVALUE_BM (_.resv));
    }
  else if (_.connob == k_postponed_send && nodw == 5)
    {
      _.recv = nodenthson_BM (_.nodv, 0);
      _.obsel = objectcast_BM (nodenthson_BM (_.nodv, 1));
      _.arg1v = nodenthson_BM (_.nodv, 2);
      _.arg2v = nodenthson_BM (_.nodv, 3);
      _.arg3v = nodenthson_BM (_.nodv, 4);
      DBGPRINTF_BM
        ("run_postponed_node_BM should send recv=%s obsel=%s arg1v=%s arg2v=%s arg3v=%s",
         OUTSTRVALUE_BM (_.recv), objectdbg_BM (_.obsel),
         OUTSTRVALUE_BM (_.arg1v), OUTSTRVALUE_BM (_.arg2v),
         OUTSTRVALUE_BM (_.arg3v));
      _.resv =
        send3_BM (_.recv, _.obsel, CURFRAME_BM, _.arg1v, _.arg2v, _.arg3v);
      DBGPRINTF_BM
        ("run_postponed_node_BM sent recv=%s obsel=%s arg1v=%s arg2v=%s arg3v=%s got resv=%s",
         OUTSTRVALUE_BM (_.recv), objectdbg_BM (_.obsel),
         OUTSTRVALUE_BM (_.arg1v), OUTSTRVALUE_BM (_.arg2v),
         OUTSTRVALUE_BM (_.arg3v), OUTSTRVALUE_BM (_.resv));
    }
  else
    {
      WARNPRINTF_BM ("run_postponed_node_BM bad nodv=%s",
                     OUTSTRVALUE_BM (_.nodv));
      WEAKASSERTWARN_BM (false && "run_postponed_node_BM bad nodv");
      LOCALRETURN_BM (NULL);
    }
  LOCALRETURN_BM (_.resv);
}                               /* end run_postponed_BM */


void
gcmarkpostponed_BM (struct garbcoll_stBM *gc)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  pthread_mutex_lock (&ti_agendamtx_BM);
  for (struct agenda_postpone_stBM * curapo = agpostpone_first_BM;
       curapo != NULL; curapo = curapo->agpo_next)
    {
      ASSERT_BM (curapo->agpo_magic == POSTPONE_MAGIC_BM);
      VALUEGCPROC_BM (gc, curapo->agpo_todo, 0);
      if (curapo->agpo_recv)
        gcobjmark_BM (gc, curapo->agpo_recv);
      VALUEGCPROC_BM (gc, curapo->agpo_arg1, 0);
      VALUEGCPROC_BM (gc, curapo->agpo_arg2, 0);
      VALUEGCPROC_BM (gc, curapo->agpo_arg3, 0);
    }
  pthread_mutex_unlock (&ti_agendamtx_BM);
}                               /* end gcmarkpostponed_BM */

/****************
 **                           for Emacs...
 ** Local Variables: ;;
 ** compile-command: "./Build" ;;
 ** End: ;;
 ****************/

/***** end of file agenda_BM.c ****/
