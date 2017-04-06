GCC=g++
AR ?=ar
CXXFLAGS=--std=c++17 -I../
ARFLAGS ?=rcs
OBJDIR=./obj
LIBDIR=./lib

LIBS=${LIBDIR}/libfiles.a
FILES=${OBJDIR}/bitmap.o ${OBJDIR}/binaryfile.o

all: ${OBJDIR} ${LIBDIR} ${FILES} ${LIBS}

clean:
	rm -f ${FILES}
	rm -Rf ${OBJDIR} ${LIBDIR}

${OBJDIR}:
	mkdir ${OBJDIR}

${LIBDIR}:
	mkdir ${LIBDIR}

${OBJDIR}/%.o: %.cc
	$(GCC) ${CXXFLAGS} -o $@ -c $<

${LIBDIR}/lib%.a: ${FILES}
	$(AR) ${ARFLAGS} $@ $?
