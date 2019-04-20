CXX = $(shell wx-config --cxx)
FLAGS = $(shell wx-config --cxxflags)
LIBS = $(shell wx-config --libs)

FILES := program_table.cpp data_table.cpp main_frame.cpp

all:
	$(CXX) -std=c++17 main.cpp $(FLAGS) $(LIBS) -o main $(FILES)

clean:
	rm -f *.o main

# CXX = $(shell wx-config --cxx)
# 
# PROGRAM = main
# 
# OBJECTS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
# 
# .SUFFIXES = .o .cpp
# 
# .cpp.o:
# 	$(CXX) --std=c++17 -c `wx-config --cxxflags` -o $@ $<
# 
# all: $(PROGRAM)
# 
# $(PROGRAM): $(OBJECTS)
# 	$(CXX) -o $(PROGRAM) $(OBJECTS) `wx-config --libs`
# 
# clean:
# 	rm -f *.o $(PROGRAM)

