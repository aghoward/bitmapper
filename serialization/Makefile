GCC=g++
OBJDIR=./obj
OBJECTS=${OBJDIR}/serializationhelper.o

all: ${OBJDIR} ${OBJECTS}

test:
	$(MAKE) -C tests

clean:
	rm -f ${OBJECTS}
	rm -Rf ${OBJDIR}
	$(MAKE) -C tests clean

${OBJDIR}:
	mkdir ${OBJDIR}

${OBJDIR}/%.o: %.cc %.h
	$(GCC) ${CXXFLAGS} -o $@ -c $<
