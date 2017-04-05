GCC=g++
CXXFLAGS+=-I../
OBJDIR=./obj

HEADERS=${OBJDIR}/bitmapheader.o ${OBJDIR}/bitmapcoreheader.o ${OBJDIR}/colortableheader.o ${OBJDIR}/elfheader.o ${OBJDIR}/sectionheader.o ${OBJDIR}/programheader.o

all: ${OBJDIR} ${HEADERS}

clean:
	rm -f ${HEADERS}
	rm -Rf ${OBJDIR}
	$(MAKE) -C tests clean

${OBJDIR}:
	mkdir ${OBJDIR}

${OBJDIR}/%.o: %.cc
	$(GCC) ${CXXFLAGS} -o $@ -c $<

