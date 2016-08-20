CC = g++
CFLAGS = -std=c++11 

all: numbers

execution-time:
	$(CC) $(CFLAGS) execution-time.cpp -o time-sample.program

numbers:
	$(CC) $(CFLAGS) numbers.cpp -o gen-numbers.program
