#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/users/isabdr/clockwork/unoptimized_conv_3_3_proj/solution1/.autopilot/db/a.g.bc ${1+"$@"}
