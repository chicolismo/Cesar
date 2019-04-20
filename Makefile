ifeq ($(OS), Windows_NT)
CXX = $(shell /c/wxWidgets-3.1.2/build-msw-shared/lib/wx/config/msw-unicode-3.1 --cxx)
FLAGS = $(shell /c/wxWidgets-3.1.2/build-msw-shared/lib/wx/config/msw-unicode-3.1 --cxxflags)
LIBS = $(shell /c/wxWidgets-3.1.2/build-msw-shared/lib/wx/config/msw-unicode-3.1 --libs)
else
CXX = $(shell wx-config --cxx)
FLAGS = $(shell wx-config --cxxflags)
LIBS = $(shell wx-config --libs)
endif

WCXX = $(shell /Users/chico/Downloads/wxWidgets-3.1.2/build-msw/lib/wx/config/inplace-x86_64-w64-mingw32-msw-unicode-static-3.1 --cxx)
WFLAGS = $(shell /Users/chico/Downloads/wxWidgets-3.1.2/build-msw/lib/wx/config/inplace-x86_64-w64-mingw32-msw-unicode-static-3.1 --cxxflags)
WLIBS = $(shell /Users/chico/Downloads/wxWidgets-3.1.2/build-msw/lib/wx/config/inplace-x86_64-w64-mingw32-msw-unicode-static-3.1 --libs)

FILES := program_table.cpp data_table.cpp main_frame.cpp

all:
	$(CXX) -std=c++17 main.cpp $(FLAGS) $(LIBS) -o main $(FILES)

windows:
	$(WCXX) -static -static-libgcc -static-libstdc++ -std=c++17 main.cpp $(WFLAGS) $(WLIBS) -o main.exe $(FILES)

clean:
	rm -f *.o main main.exe

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

