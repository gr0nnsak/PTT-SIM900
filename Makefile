CC = g++
CFLAGS = -O1 -Wall -g
LDFLAGS = -lm

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
DEPENDENCIES = $(addprefix .,$(SOURCES:.cpp=.d))

.PHONY: clean all

all: main

main: main.cpp
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

clean:
	$(RM) main $(OBJECTS) $(DEPENDENCIES)

-include $(DEPENDENCIES)
