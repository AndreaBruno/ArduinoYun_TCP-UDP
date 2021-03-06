#!/bin/ash

DEV=/dev/ttyATH0
PORT=50000
BAUD=9600

while true; do 
        if [ -e $DEV ]
        then
                socat tcp-l:$PORT,reuseaddr,fork file:$DEV,nonblock,raw,echo=0,waitlock=/var/run/tty,b$BAUD
        else
                sleep 2
        fi
done
