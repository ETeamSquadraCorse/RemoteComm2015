#!/bin/sh

# SPlayer.sh
#
# It outputs data to the speakers
# Its parameters are:
#   raw format:	-t raw
#   8 kHz:	-r 8000
#   8 bit mono:	-f U8
#
# The generated audio data is sent to the stdout stream

aplay -t raw -r 8000 -f U8
