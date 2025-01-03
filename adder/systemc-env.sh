#!/bin/bash
# systemc-env.sh: Set up the environment for SystemC
########################################################################
# Author:  Torsten MAEHNE <Torsten.Maehne@lip6.fr>
# Created: 2014-01-30
########################################################################
#
# This shell script prepares the shell environment for building or
# using the SystemC libraries. You can either source it from the command
# line or in your .bashrc:
#
# . ./systemc-env.sh [--build-version=2.2|2.3.0|2.3.1|2.3.3]
#                    [--build-type=Debug|Release] \
#                    [-h|--help] \
#                    [-v|--version] \
#
########################################################################
export BOOST_ROOT=/usr
export SYSTEMC_ARCH=linux64
export TARGET_ARCH=
#export SYSTEMC_ROOT=/users/outil/riscv/systemc-2.3.3 
export SYSTEMC_ROOT=/users/outil/systemcams/systemc-2.3.1
export SYSTEMC_HOME=$SYSTEMC_ROOT
export SYSTEMC_INCLUDE_DIRS="-I$SYSTEMC_ROOT/include"
export SCV_HOME=$SYSTEMC_ROOT
export TLM_HOME=$SYSTEMC_ROOT
export SYSTEMC_LIBRARY_DIRS="-Wl,-rpath=$SYSTEMC_HOME/lib-$SYSTEMC_ARCH -L$SYSTEMC_HOME/lib-$SYSTEMC_ARCH"
export PATH=$PATH:/opt/soclib/utils/bin:/opt/mipsel-unknown-elf/bin:/users/outil/riscv/riscv32-unknown-elf/bin
export SYSTEMC=$SYSTEMC_HOME
export TLM2=$TLM_HOME
export SYSTEMC_AMS=$SYSTEMC_AMS_HOME
