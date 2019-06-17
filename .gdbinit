# file bismon/.gdbinit
# GPLv3+ licensed
### see https://stackoverflow.com/a/56407988/841108
add-auto-load-safe-path ./.gdbinit
break abort
break abort_BM
set max-value-size 33554432
