CFLAGS = -Wall --pedantic-errors -O2

lin_shell: main.o directory.o
	g++ ${CFLAGS} directory.o main.o -o lin_shell

.PHONY:debug
debug: CFLAGS = -g -Wall --pedantic-errors
debug: program

main.o: main.cpp directory.h
	g++ ${CFLAGS} -c main.cpp

directory.o: directory.cpp directory.h
	g++ ${CFLAGS} -c directory.cpp
