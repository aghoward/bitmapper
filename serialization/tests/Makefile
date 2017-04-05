GCC=g++
TESTCXXFLAGS += -I../ -g
OBJDIR=./obj
UUTDIR=../obj

TESTS = ${OBJDIR}/serializationhelper_tests.o
UUTS = ${UUTDIR}/*.o

all: unittests

${OBJDIR}:
	mkdir ${OBJDIR}

clean:
	rm -f unittests ${TESTS}
	rm -Rf ${OBJDIR}

${OBJDIR}/%_tests.o: %_tests.cc ${OBJDIR}
	$(GCC) ${CXXFLAGS} ${TESTCXXFLAGS} -o $@ -c $<

unittests: ${TESTS} ${UUTS} ${GTESTLIB}
	$(GCC) ${CXXFLAGS} ${TESTCXXFLAGS} -o $@ -lpthread $^
