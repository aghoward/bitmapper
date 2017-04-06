GCC=g++
AR ?=ar
OBJDIR=./obj
LIBDIR=./lib
OBJECTS=${OBJDIR}/serializationhelper.o
LIBS=${LIBDIR}/libserialization.a

all: ${OBJDIR} ${LIBDIR} ${OBJECTS} ${LIBS}

test:
	$(MAKE) -C tests

clean:
	rm -f ${OBJECTS}
	rm -Rf ${OBJDIR}
	rm -Rf ${LIBDIR}
	$(MAKE) -C tests clean

${OBJDIR}:
	mkdir ${OBJDIR}

${LIBDIR}:
	mkdir ${LIBDIR}

${LIBDIR}/lib%.a: ${OBJECTS}
	$(AR) ${ARFLAGS} $@ $?

${OBJDIR}/%.o: %.cc %.h
	$(GCC) ${CXXFLAGS} -o $@ -c $<
