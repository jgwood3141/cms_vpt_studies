#!/bin/csh

#
# Initializer
#
echo 'Hello'


#
# Execute data plotting macro
#
echo 'Running VPT plotting macro'
root -l -b -q ../macros/vpt_fits.C++


#
# Outro
#
echo 'Goodbye'
