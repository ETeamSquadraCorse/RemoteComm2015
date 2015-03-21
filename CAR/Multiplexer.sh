#!/bin/sh

# Multiplexer.sh

# Creates a FIFO nodes

if [ -e FIFOVoice ]; then
  rm FIFOVoice
fi

mknod FIFOVoice p

if [ -e FIFOData ]; then
  rm FIFOData
fi

mknod FIFOData p

./Multiplexer.out
