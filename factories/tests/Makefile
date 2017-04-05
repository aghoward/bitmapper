GCC ?=g++

GTESTROOT ?=/home/howard/repos/googletest/googletest
GMOCKROOT ?=/home/howard/repos/googletest/googlemock
GTESTLIB ?=${GTESTROOT}/make/gtest_main.a
GMOCKLIB ?=${GMOCKROOT}/make/gmock_main.a

CXXFLAGS ?=--std=c++17
TESTCXXFLAGS ?=-rdynamic -pthread -I${GTESTROOT} -I${GTESTROOT}/include -I${GMOCKROOT} -I${GMOCKROOT}/include
CXXFLAGS += -I../ -I../../ -g
TESTCXXFLAGS += -I./mocks

OBJDIR=./obj
UUTDIR=../obj

TESTS = ${OBJDIR}/colortableheaderfactory_tests.o ${OBJDIR}/bitmapcoreheaderfactory_tests.o ${OBJDIR}/bitmapheaderfactory_tests.o ${OBJDIR}/bitmapfactory_tests.o
UUTS = ${UUTDIR}/*.o

all: unittests

${OBJDIR}:
	mkdir ${OBJDIR}

clean:
	rm -f unittests ${TESTS}
	rm -Rf ${OBJDIR}

${OBJDIR}/%_tests.o: %_tests.cc ${OBJDIR}
	$(GCC) ${CXXFLAGS} ${TESTCXXFLAGS} -o $@ -c $<

unittests: ${TESTS} 
	$(GCC) ${CXXFLAGS} ${TESTCXXFLAGS} -o $@ -lpthread $^ ${UUTS} ${GTESTLIB} ${GMOCKLIB} ../../files/obj/*.o ../../headers/obj/*.o ../../serialization/obj/*.o 
