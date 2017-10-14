Buffer:	Buffer.o main.o
	g++ Buffer.o main.o -o exe

main.o: main.cpp Buffer.h
	g++ -c main.cpp

Buffer.o: Buffer.cpp Buffer.h
	g++ -c Buffer.cpp 
