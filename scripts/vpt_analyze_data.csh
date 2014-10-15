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
# Outro
#
echo 'Goodbye'
