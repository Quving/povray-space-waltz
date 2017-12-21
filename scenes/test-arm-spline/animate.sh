#!/bin/bash

prefix=$1
duration=$2

if [ -z "$duration" ]; then
    echo "Duration?"
elif [ -z "prefix" ]; then
    echo "Prefix"
fi

no_of_pngs=$(ls *.png | wc -l)
fps=$(echo $(($no_of_pngs/$duration)))

if [ "$fps" == "0" ]; then
    fps=1
fi

echo "Create animation with duration of $duration seconds and $fps fps..."
ffmpeg -r $fps -start_number 1 -i $1%0${#no_of_pngs}d.png $1-animation.mp4
