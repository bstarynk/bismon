# file genscripts/straight-gcc-config.bash
# under github.com/bstarynk/bismon/
# to be source-d by GNU bash scripts
GCC=/usr/bin/gcc-10

if [ ! -x "$GCC" ]; then
    printf "BISMON straight-gcc-config with missing %s compiler\n" "$GCC" > /dev/stderr
    exit 1
fi
