CXX = g++
CXXFLAGS = -std=c++11 -lpthread
TARGET = task8exe
SRCS = main.cpp MySingleton.cpp

all: task8exe

task8exe: $(SRCS)
	$(CXX) -o task8exe $(SRCS) $(CXXFLAGS)

clean:
	rm -f task8exe