CC = g++
CFLAGS = -std=c++11 -Wextra
LDFLAGS= 
EXEC = sorting
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)


$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC) $(LDFLAGS)



%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(EXEC) $(OBJECTS)
