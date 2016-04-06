CXX = g++-4.9
CXXFLAGS = -g -Wall -Werror -std=c++11 -MMD
MAKEFILE_NAME = ${firstword ${MAKEFILE_LIST}}

OBJECTS = bottlingplant.o truck.o student.o nameserver.o  watcard.o printer.o watcardoffice.o cardeater.o overcharge.o vendingmachine.o watcola.o

EXEC = soda

DEPENDS = ${OBJECTS:.o=.d}


${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}


-include ${DEPENDS}

.PHONY : clean

clean :
	rm -f ${DEPENDS} ${OBJECTS} ${EXECS}

