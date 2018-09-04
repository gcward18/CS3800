CFLAGS = -Wall -std=c++11 --pedantic-errors -O2

program: main.o directory.o shell.o file.o folder.o
	g++ ${CFLAGS} directory.o shell.o main.o file.o folder.o -o program

.PHONY:debug
debug: CFLAGS = -g -Wall --pedantic-errors
debug: program

main.o: main.cpp directory.h
	g++ ${CFLAGS} -c main.cpp

directory.o: directory.h directory.cpp folder.o file.o
	g++ ${CFLAGS} folder.o file.o -c directory.cpp

shell.o: shell.h shell.cpp
	g++ ${CFLAGS} -c shell.cpp

file.o: file.h file.cpp
	g++ ${CFLAGS} -c file.cpp

folder.o: folder.h folder.cpp
	g++ ${CFLAGS} -c folder.cpp

test: test.o directory.o file.o folder.o
	g++ ${CFLAGS} test.o directory.o file.o folder.o -o test

test.o: test.cpp
	g++ ${CFLAGS} -c test.cpp

clean:
	rm *.o program test
