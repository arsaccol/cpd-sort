CC = g++
CFLAGS = -std=c++11 

all: testbed

debug:
	$(CC) $(CFLAGS) -g testbed.cpp numbers.o insertion_sort.o heapsort.o timer.o -o tests.program

testbed: numbers.o heap_sort.o insertion_sort.o timer.o
	$(CC) $(CFLAGS) testbed.cpp numbers.o insertion_sort.o heapsort.o timer.o -o tests.program

numbers.o: numbers.cpp
	$(CC) $(CFLAGS) -c numbers.cpp 

insertion_sort.o: insertion_sort.cpp
	$(CC) $(CFLAGS) -c insertion_sort.cpp

heap_sort.o: heapsort.cpp
	$(CC) $(CFLAGS) -c heapsort.cpp


timer.o: timer.cpp
	$(CC) $(CFLAGS) -c timer.cpp

clean:
	rm -rf *.o *.program *.csv

delete_numbers:
	rm *.nr
