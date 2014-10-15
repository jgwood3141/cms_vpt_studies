#!/bin/csh

#
# Initializer
#
echo 'Hello'


#
# Execute data plotting macro
#
echo 'Running VPT plotting macro'
root -l -b -q ../macros/vpt_plots.C++


#
# Outro
#
echo 'Goodbye'
