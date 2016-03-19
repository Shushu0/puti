TARGET = Linux
MAKE   = make
ARFLAGS = rs
WARNING_FLAGS = -Wall -Werror -Wno-unused -Wmissing-declarations
CFLAGS = -O2 $(WARNING_FLAGS) -g
CXXFLAGS = $(CFLAGS) 
RM_F   = rm -f
