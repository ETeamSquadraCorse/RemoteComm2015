#!/bin/sh

# MSampler.sh
#
# It takes data from the microphone
# Its parameters are:
#   raw format:	-t raw
#   8 kHz:	-r 8000
#   8 bit mono:	-f U8
#   quite:	-q
#
# The generated audio data is sent to the stdout stream

arecord -t raw -r 8000 -f U8 -q
