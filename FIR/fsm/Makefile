SYSTEMC_ARCH = linux

OPT    = -O3
DEBUG  = -g
OTHER  = -Wall -Wno-deprecated
CXXFLAGS =  $(OTHER) $(DEBUG)
# CFLAGS = $(DEBUG) $(OTHER)

MODULE = run
SRCS = driver.cpp fsm.cpp fsm_main.cpp monitor.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY:	clean

include ./Makefile.defs

clean::
	rm -f *.vcd Makefile.deps
