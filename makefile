CC = g++
CFLAGS = -std=c++11 

all: testbed

testbed: numbers
	$(CC) $(CFLAGS) testbed.cpp numbers.o -o tests.program

numbers:
	$(CC) $(CFLAGS) numbers.cpp -c

clean:
	rm -rf *.o *.program

delete_numbers:
	rm *.nr
