CC = g++
CFLAGS = -O1 -Wall -g
LDFLAGS = -lm -lrt -lm -lasound -ljack -pthread

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
DEPENDENCIES = $(addprefix .,$(SOURCES:.cpp=.d))
PORTAUDIO = libportaudio.a

.PHONY: clean all

all: main

main: main.cpp
	$(CC) $^ $(CFLAGS) $(PORTAUDIO) $(LDFLAGS) -o $@

clean:
	$(RM) main $(OBJECTS) $(DEPENDENCIES)

-include $(DEPENDENCIES)
