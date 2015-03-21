CC = g++
CFLAGS = -Wall
LDFLAGS = -lpthread
OBJECTS = $(SOURCES:.cpp=.o)

all: Multiplexer MFilter

Multiplexer: Multiplexer.cpp
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

MFilter: MFilter.cpp
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -rf Multiplexer
	rm -rf MFilter
	rm -rf FIFOData
	rm -rf FIFOVoice
	rm -rf *.o
