CC = g++
CFLAGS = -Wall -g

SOURCES := $(wildcard *.cpp) $(wildcard *.c)
BINS := $(SOURCES:%.cpp=bin/%)
BINS := $(BINS:%.c=bin/%)

all: $(BINS)

bin/%: %.cpp
	mkdir -p bin
	$(CC) $(CFLAGS) $< -o $@

bin/%: %.c
	mkdir -p bin
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf bin