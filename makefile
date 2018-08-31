CFLAGS = -Wall -std=c++11 --pedantic-errors -O2

program: main.o directory.o shell.o
	g++ ${CFLAGS} directory.o shell.o main.o -o program

.PHONY:debug
debug: CFLAGS = -g -Wall --pedantic-errors
debug: program

main.o: main.cpp directory.h
	g++ ${CFLAGS} -c main.cpp

directory.o: directory.h directory.cpp
	g++ ${CFLAGS} -c directory.cpp

shell.o: shell.h shell.cpp
	g++ ${CFLAGS} -c shell.cpp

test: test.o
	g++ ${CFLAGS} test.o -o test

test.o: test.cpp
	g++ ${CFLAGS} -c test.cpp

clean:
	rm *.o program test
