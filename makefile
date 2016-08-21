CC = g++
CFLAGS = -std=c++11 

all: testbed

testbed: numbers builddir
	$(CC) $(CFLAGS) testbed.cpp numbers.o -o build/tests

numbers:
	$(CC) $(CFLAGS) numbers.cpp -c
builddir:
	mkdir -p build
clean:
	rm -rf *.o ./build
