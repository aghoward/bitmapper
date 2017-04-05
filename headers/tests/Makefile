CXXFLAGS += -I../ -I../../ -g
OBJDIR=./obj
UUTDIR=../obj

TESTS = ${OBJDIR}/bitmapheader_tests.o ${OBJDIR}/bitmapcoreheader_tests.o ${OBJDIR}/colortableheader_tests.o
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
	$(GCC) ${CXXFLAGS} ${TESTCXXFLAGS} -o $@ $^ ../../serialization/obj/serializationhelper.o
