#!/bin/bash

# Go to src directory
cd ../src

# Compile test/generate.cpp
g++ naive.cpp -std=c++20 -DLOCAL -o naive

echo "Compiled naive.cpp"

# Create the time_taken_naive.txt file if it doesn't exist
touch ../plots/time_taken_naive.txt

# Clear the time_taken_naive.txt file
echo -n "" >../plots/time_taken_naive.txt

echo "Running naive.cpp"

# Generate output files
for i in $(seq 1 $1); do
  echo "Running Test $i... "
  # ./naive < "../test/input/test$i.in" > "../test/output_naive/test$i.out"
  { time ./naive <"../test/input/test$i.in" >"../test/output_naive/test$i.out"; } 2>&1 | grep real | awk '{print $2}' >>../plots/time_taken_naive.txt
done
