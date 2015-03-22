#!/bin/sh

# Run.sh
#
# This script executes all the other scripts, in correct order,
# for creating a working communication infrastructure from then
# car side

./Multiplexer.sh | ./Sender.sh &

sleep 2

./MSampler.sh | ./MWorker.sh > FIFOVoice &