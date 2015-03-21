#!/bin/sh

# Demultiplexer.sh

# Receives data from stdin and separates voice from car data.
# The data is stored into FIFO files.

if [ -e FIFOVoice ]; then
  rm FIFOVoice
fi

mknod FIFOVoice p

if [ -e FIFOData ]; then
  rm FIFOData
fi

mknod FIFOData p

./Demultiplexer.out
