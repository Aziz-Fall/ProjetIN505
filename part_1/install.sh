#!/bin/bash
DIR=build/
if [ ! -d "$DIR" ]; then
    mkdir $DIR
    cmake $DIR
    cd $DIR
    make 
    ./part_1
    echo "build projet :)"
else
    cmake $DIR
    cd $DIR
    make 
    ./part_1
fi 

