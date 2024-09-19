# Compiler settings
CXX = g++
CXXFLAGS = -Wall -std=c++11 -pthread --coverage
LDFLAGS = -pthread

all: graph

# Link the executable
graph: main.o Graph.o
	$(CXX) $(CXXFLAGS) -o graph main.o Graph.o $(LDFLAGS)

# Object file generation
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Graph.o: Graph.cpp
	$(CXX) $(CXXFLAGS) -c Graph.cpp

# Clean up
clean:
	rm -f graph main.o Graph.o *.gcda *.gcno *.gcov

# Run Valgrind
valgrind: graph
	valgrind --leak-check=full ./graph

# Generate coverage report for project files only
coverage: graph
	./graph
	gcov main.cpp
	gcov Graph.cpp

.PHONY: all clean valgrind coverage
