#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/users/isabdr/clockwork/unoptimized_mini_conv_halide_fixed_proj/solution1/.autopilot/db/a.g.bc ${1+"$@"}
