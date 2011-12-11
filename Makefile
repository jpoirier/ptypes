#
# Makefile for all Unix platforms, places the library in lib/,
# the shared library in so/. Also builds the test program
# src/ptypes_test and the sample program bin/wshare.
#

UMAKEFILE=Makefile.`uname`

all:
	cd src ; make -f $(UMAKEFILE) all
#	cd wshare ; make -f $(UMAKEFILE) all

clean:
	cd src ; make -f $(UMAKEFILE) clean
	cd wshare ; make -f $(UMAKEFILE) clean

clean-src:
	cd src ; make -f $(UMAKEFILE) clean-src
	cd wshare ; make -f $(UMAKEFILE) clean-src

install:
	cd src ; make -f $(UMAKEFILE) install

uninstall:
	cd src ; make -f $(UMAKEFILE) uninstall

