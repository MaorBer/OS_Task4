# Compiler settings
CXX = g++
CXXFLAGS = -Wall -std=c++11
LDFLAGS = -pthread

# Files
SRC = main.cpp Graph.cpp
OBJS = main.o Graph.o
EXEC = graph

all: $(EXEC)

# Link the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

# Object file generation
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Graph.o: Graph.cpp
	$(CXX) $(CXXFLAGS) -c Graph.cpp -o Graph.o

# Clean up
clean:
	rm -f $(EXEC) $(OBJS)

# Run Valgrind
valgrind: $(EXEC)
	valgrind --leak-check=full ./$(EXEC)

.PHONY: all clean valgrind
