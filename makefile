CC = g++
CFLAGS = -std=c++11 

all: testbed

debug:
	$(CC) $(CFLAGS) -g testbed.cpp numbers.o insertion_sort.o heapsort.o timer.o -o tests.program

testbed: numbers heap_sort timer
	$(CC) $(CFLAGS) testbed.cpp numbers.o insertion_sort.o heapsort.o timer.o -o tests.program

numbers:
	$(CC) $(CFLAGS) numbers.cpp -c

insertion_sort:
	$(CC) $(CFLAGS) insertion_sort.cpp -c

heap_sort:
	$(CC) $(CFLAGS) heapsort.cpp -c


timer:
	$(CC) $(CFLAGS) timer.cpp -c

clean:
	rm -rf *.o *.program *.csv

delete_numbers:
	rm *.nr
