export GCC=g++
export ROOTDIR = $(shell pwd)
export CXXFLAGS=--std=c++17 -I${ROOTDIR}
export GTESTROOT ?= /home/howard/repos/googletest/googletest
export GTESTLIB = ${GTESTROOT}/make/gtest_main.a
export GMOCKROOT ?= /home/howard/repos/googletest/googlemock
export GMOCKLIB = ${GMOCKROOT}/make/gmock_main.a

export TESTCXXFLAGS=-g -pthread -I${ROOTDIR}/serialization -I${ROOTDIR}/headers -I${ROOTDIR}/factories -I${ROOTDIR}/files -I${ROOTDIR}/factories/tests/mocks -I${GTESTROOT} -I${GTESTROOT}/include -I${GMOCKROOT} -I${GMOCKROOT}/include

TESTLIBS=serialization/tests/obj/*.o headers/tests/obj/*.o factories/tests/obj/*.o 
UUTLIBS=factories/obj/*.o files/obj/*.o headers/obj/*.o serialization/obj/*.o 

all:
	$(MAKE) -C serialization
	$(MAKE) -C headers
	$(MAKE) -C factories
	$(MAKE) -C files

clean:
	$(MAKE) -C serialization clean
	$(MAKE) -C headers clean
	$(MAKE) -C factories clean
	$(MAKE) -C files clean
	rm -f unittests


tests: all
	$(MAKE) -C serialization/tests
	$(MAKE) -C headers/tests
	$(MAKE) -C factories/tests
	$(GCC) ${CXXFLAGS} ${TESTCXXFLAGS} -o unittests -lpthread ${TESTLIBS} ${UUTLIBS} ${GTESTLIB} ${GMOCKLIB}
