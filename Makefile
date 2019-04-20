CXX = $(shell wx-config --cxx)
FLAGS = $(shell wx-config --cxxflags)
LIBS = $(shell wx-config --libs)

all:
	$(CXX) -std=c++17 main.cpp $(FLAGS) $(LIBS) -o main

clean:
	rm -f *.o main
