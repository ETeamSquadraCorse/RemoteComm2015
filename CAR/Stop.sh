#!/bin/sh

# Stop.sh
#
# This script stops all the other scripts, in correct order,
# for correctly closing the car communication infrastructure

pkill MSampler.sh

pkill MFilter.out

pkill Multiplexer.out

pkill Sender.out
