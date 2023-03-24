#!/bin/bash

# Go to test directory
cd ../test

# Compile test/generate.cpp
g++ generate.cpp -std=c++20 -DLOCAL -o generate

# Generate input files
for i in $(seq 1 $1); do
    echo "Generating Test $i... " 
    ./generate > "input/test$i.in"
done
