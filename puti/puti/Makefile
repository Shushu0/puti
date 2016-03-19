BASE = ../

-include $(BASE)/port.mak

base = File Log Time
net  = InetAddr Socket


all : libputi.a


BASEOBJS = $(addprefix base/, $(addsuffix .o, $(base)))
NETOBJS  = $(addprefix net/, $(addsuffix .o, $(net)))

.PRECIOUS: %/%.o


libputi.a : $(BASEOBJS) $(NETOBJS)
	$(AR) $(ARFLAGS) $@ $^

clean:
	$(RM_F) $(BASEOBJS) $(NETOBJS) libputi.a
