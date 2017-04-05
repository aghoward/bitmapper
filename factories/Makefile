GCC ?=g++
CXXFLAGS ?=--std=c++17 -I../
OBJDIR=./obj

HEADERS=${OBJDIR}/colortableheaderfactory.o ${OBJDIR}/bitmapcoreheaderfactory.o ${OBJDIR}/bitmapheaderfactory.o ${OBJDIR}/bitmapfactory.o ${OBJDIR}/elfheaderfactory.o ${OBJDIR}/sectionheaderfactory.o ${OBJDIR}/programheaderfactory.o

all: ${OBJDIR} ${HEADERS}

clean:
	rm -f ${HEADERS}
	rm -Rf ${OBJDIR}
	$(MAKE) -C tests clean

${OBJDIR}:
	mkdir ${OBJDIR}

${OBJDIR}/%.o: %.cc
	$(GCC) ${CXXFLAGS} -o $@ -c $<

