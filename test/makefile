CXX=g++

EXEC=bin

GTESTINC=/usr/local/include/gtest
INC=../src
OBJ=${INC}/Serializer.o

LIBS=/usr/local/lib/libgtest.a

CXXFLAGS=-g -Wall -std=c++17 -I${GTESTINC} -I${INC}

all: test.out

test.out: test.cpp ${OBJ}
	${CXX} ${CXXFLAGS} -o $@ $^ ${LIBS}
	mkdir -p ${EXEC}; mv $@ ${EXEC}

clean:
	rm -rf ${EXEC}
