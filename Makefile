# Compiler settings
CXX = g++
CXXFLAGS = -g -O2 -Wall -Wextra -std=c++11
LDFLAGS = -pthread

# Files
SRC = main.cpp Graph.cpp
OBJS = $(SRC:.cpp=.o)
EXEC = graph_exercise

# Test coverage and profiling
CXXFLAGS += --coverage
LDFLAGS += -lgcov

all: $(EXEC)

# Link the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

# Object file generation
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(EXEC) $(OBJS) *.gcda *.gcno *.gcov

# Run code coverage
coverage: $(EXEC)
	./$(EXEC)
	gcov $(SRC)

# Run gprof for profiling
profile: $(EXEC)
	./$(EXEC)
	gprof $(EXEC) gmon.out > analysis.txt

# Run Valgrind
valgrind: $(EXEC)
	valgrind --leak-check=full --track-origins=yes ./$(EXEC)

# Run Valgrind call graph
callgraph: $(EXEC)
	valgrind --tool=callgrind ./$(EXEC)
	callgrind_annotate callgrind.out.* > callgraph.txt

# Targets for task 5 and task 7 code
hello: hello.c
	gcc -g -o hello hello.c
	valgrind --leak-check=full ./hello

race: race.c
	gcc -g -o race race.c -pthread
	valgrind --tool=helgrind ./race

.PHONY: all clean coverage profile valgrind callgraph hello race
