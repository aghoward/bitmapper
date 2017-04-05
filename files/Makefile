GCC=g++
CXXFLAGS=--std=c++17 -I../
OBJDIR=./obj

FILES=${OBJDIR}/bitmap.o

all: ${OBJDIR} ${FILES}

clean:
	rm -f ${FILES}
	rm -Rf ${OBJDIR}

${OBJDIR}:
	mkdir ${OBJDIR}

${OBJDIR}/%.o: %.cc
	$(GCC) ${CXXFLAGS} -o $@ -c $<

