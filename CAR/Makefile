CC = g++
CFLAGS = -Wall
LDFLAGS = -lpthread

all: Multiplexer.out MFilter.out

Multiplexer.out: Multiplexer.cpp
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

MFilter.out: MFilter.cpp
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -rf Multiplexer.out
	rm -rf MFilter.out
	rm -rf FIFOData
	rm -rf FIFOVoice
	rm -rf *.o

