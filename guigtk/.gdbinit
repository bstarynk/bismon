## file bismon/guigtk/.gdbinit
## SPDX-License-Identifier: LGPL-3.0-or-later
### see https://stackoverflow.com/a/56407988/841108
add-auto-load-safe-path ./.gdbinit
break abort
break error_fun
set max-value-size 33554432
