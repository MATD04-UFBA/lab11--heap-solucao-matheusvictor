.cpp.o:	
	g++	-c $*.cpp

all:	Heap

Heap:  Heap.o cMaxHeap.o
	g++ -o $@ $^

clean:
	rm *.o Heap