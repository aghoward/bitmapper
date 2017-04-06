GCC=g++
AR ?=ar
CXXFLAGS+=-I../
ARFLAGS ?=rcs
OBJDIR=./obj
LIBDIR=./lib

LIBS=${LIBDIR}/libheaders.a
HEADERS=${OBJDIR}/bitmapheader.o ${OBJDIR}/bitmapcoreheader.o ${OBJDIR}/colortableheader.o ${OBJDIR}/elfheader.o ${OBJDIR}/sectionheader.o ${OBJDIR}/programheader.o

all: ${OBJDIR} ${LIBDIR} ${HEADERS} ${LIBS}

clean:
	rm -f ${HEADERS}
	rm -Rf ${OBJDIR}
	$(MAKE) -C tests clean

${OBJDIR}:
	mkdir ${OBJDIR}

${LIBDIR}:
	mkdir ${LIBDIR}

${OBJDIR}/%.o: %.cc
	$(GCC) ${CXXFLAGS} -o $@ -c $<

${LIBDIR}/lib%.a: ${HEADERS}
	$(AR) ${ARFLAGS} $@ $?
