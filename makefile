CC = g++
CFLAGS = -std=c++11 

all: testbed

testbed: numbers insertion_sort
	$(CC) $(CFLAGS) testbed.cpp numbers.o insertion_sort.o -o tests.program

numbers:
	$(CC) $(CFLAGS) numbers.cpp -c

insertion_sort:
	$(CC) $(CFLAGS) insertion_sort.cpp -c

clean:
	rm -rf *.o *.program

delete_numbers:
	rm *.nr
