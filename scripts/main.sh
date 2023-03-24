#!/bin/bash

# Go to src directory
cd ../src

# Compile test/generate.cpp
g++ main.cpp -std=c++20 -DLOCAL -o main

echo "Compiled main.cpp"

# Create the time_taken_main.txt file if it doesn't exist
touch ../plots/time_taken_main.txt

# Clear the time_taken_main.txt file
echo -n "" >../plots/time_taken_main.txt

echo "Running main.cpp"

# Generate output files
for i in $(seq 1 $1); do
  echo "Running Test $i... "
  # ./main < "../test/input/test$i.in" > "../test/output_main/test$i.out"
  { time ./main <"../test/input/test$i.in" >"../test/output_main/test$i.out"; } 2>&1 | grep real | awk '{print $2}' >>../plots/time_taken_main.txt
done
