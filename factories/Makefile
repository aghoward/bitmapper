GCC ?=g++
AR ?=ar
CXXFLAGS ?=--std=c++17 -I../
ARFLAGS ?=rcs
OBJDIR=./obj
LIBDIR=./lib

LIBS=${LIBDIR}/libfactories.a
HEADERS=${OBJDIR}/colortableheaderfactory.o ${OBJDIR}/bitmapcoreheaderfactory.o ${OBJDIR}/bitmapheaderfactory.o ${OBJDIR}/bitmapfactory.o ${OBJDIR}/elfheaderfactory.o ${OBJDIR}/sectionheaderfactory.o ${OBJDIR}/programheaderfactory.o

all: ${OBJDIR} ${LIBDIR} ${HEADERS} ${LIBS}

clean:
	rm -f ${HEADERS}
	rm -Rf ${OBJDIR} ${LIBDIR}
	$(MAKE) -C tests clean

${OBJDIR}:
	mkdir ${OBJDIR}

${LIBDIR}:
	mkdir ${LIBDIR}

${OBJDIR}/%.o: %.cc
	$(GCC) ${CXXFLAGS} -o $@ -c $<

${LIBDIR}/lib%.a: ${HEADERS}
	$(AR) ${ARFLAGS} $@ $?
