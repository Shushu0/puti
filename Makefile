BASE = .
-include $(BASE)/port.mak
all : lib

lib :
	$(MAKE) -C puti/


clean :
	$(MAKE) -C puti/ clean
