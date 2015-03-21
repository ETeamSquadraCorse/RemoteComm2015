#!/bin/sh

# Multiplexer.sh

# Creates a FIFO nodes

if [ -e FIFOVoice ]; then
  echo "Removing FIFOVoice node"
  rm FIFOVoice
fi

echo "Creating FIFOVoice node"
mknod FIFOVoice p

if [ -e FIFOData ]; then
  echo "Removing FIFOData node"
  rm FIFOData
fi

echo "Creating FIFOData node"
mknod FIFOData p

./Multiplexer.out
