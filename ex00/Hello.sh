#!/bin/bash

while true # Infinite Loop
    # Prints "yes" and pipes it to head to assure we print first or one line at a time.
    do yes "yes" | head -n 1
    # Sleep to control the speed
    sleep 1
done