# Makefile.cmd

all: main

main: main.o Sap.o
    g++ -o main main.o Sap.o

main.o: main.cpp Sap.h
    g++ -c main.cpp

Sap.o: Sap.cpp Sap.h
    g++ -c Sap.cpp

clean:
    rm -f main *.o