#!/bin/csh

#
# Initializer
#
echo 'Hello'

#
# Execute data analyzer macro
#
echo 'Running VPT analzying macro'
root -l -b -q ../macros/vpt_analyzer.C++


#
# Execute data plotting macro
#
echo 'Running VPT plotting macro'
root -l -b -q ../macros/vpt_plots.C++


#
# Outro
#
echo 'Goodbye'
