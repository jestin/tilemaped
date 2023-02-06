CXX = g++

SDL2CFLAGS = $(shell pkg-config sdl2 --cflags)
SDL2LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf

CXXFLAGS = -Wall -std=c++17 $(SDL2CFLAGS)
LDFLAGS = $(SDL2LIBS)

PROGRAM = tilemaped
OBJECTS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

.SUFFIXES:	.o .cpp

.cpp.o:
	$(CXX) -ggdb -c $(CXXFLAGS) -o $@ $<

all:	$(PROGRAM)

$(PROGRAM):		$(OBJECTS)
	$(CXX) -o $(PROGRAM) $(OBJECTS) $(LDFLAGS)

run: all
	./$(PROGRAM)

tags:
	ctags * --recurse

clean:
	rm -f *.o $(PROGRAM)

