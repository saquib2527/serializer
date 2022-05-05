CXX=g++

CXXFLAGS=-g -Wall -std=c++17

all: Serializer.o

Serializer.o: Serializer.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $<

clean:
	rm -f *.o

