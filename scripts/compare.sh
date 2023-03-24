#!/bin/bash

# Go to src directory
cd ../test

# Compile test/generate.cpp
g++ compare.cpp -std=c++20 -DLOCAL -o compare

# Generate output files
for i in $(seq 1 $1); do
    echo -n "Test $i: "
    ./compare  "output_main/test$i.out"  "output_naive/test$i.out"
done
