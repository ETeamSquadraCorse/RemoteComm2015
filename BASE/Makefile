CC = g++
CFLAGS = -Wall
LDFLAGS = -lpthread

all: Demultiplexer.out

Demultiplexer.out: Demultiplexer.cpp
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -rf Demultiplexer.out
	rm -rf FIFOData
	rm -rf FIFOVoice
	rm -rf *.o
