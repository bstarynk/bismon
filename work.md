# the agenda

We have a small fixed (and between 2 and 16) number of worker threads
(essentially a thread pool). See the `--jobs` arguments to `bismon`
program. Look into implementation details in `agenda_BM.c` source
file.

There is an (implicit) agenda grouping tasklet objects, of various priority.

The priorities can be `very_high`, `high`, `normal`, `low`, `very_low`.

The agenda maintains a few (changing) hash sets of tasklet objects, one set per priority.

Each worker thread loops by taking (and removing) a tasklet from the
agenda, and runs that tasklet, and repeat. The running step of a
tasklet is expected to be short (a few milliseconds) and should be
bounded (see also `taskletcputime_BM` giving its CPU time, and
`taskletelapsed_BM` giving its elapsed time) and without significant
I/O (so some "CPU-intensive" computation). A tasklet is run by sending
it the `run_tasklet` selector (without additional arguments), with the
tasklet being locked. That run would usually (but not always) add some
tasklets into the agenda.

So the agenda API is with functions like
`agenda_add_very_high_priority_tasklet_BM`
.... `agenda_add_normal_priority_tasklet_BM`
... `agenda_add_very_low_priority_tasklet_BM` adding tasklets, and
`agenda_remove_tasklet_BM` to remove a tasklet.

The worker threads are running tasklets of `very_high` then `high`
... up to `very_low` priority first. Occasionally a lower priority
task could be run (once every 32 times, randomly). The order in which
tasklets of same priority are running is unspecified (and essentially
random).
