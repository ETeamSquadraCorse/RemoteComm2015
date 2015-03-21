#!/bin/sh

# MFilter.sh
#
# This tool gets the audio data from stdin stream.
# Then applies some filtering transformation of some
# kind (maybe none, maybe compression, maybe coding...)
#
# The data is then inserted in the FIFOVoice FIFO
# pipeline file.

./MFilter.out > FIFOVoice