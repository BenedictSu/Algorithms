#!/bin/bash
g++ -g Sorting.cpp -o Sorting
./Sorting < input.txt > output.txt
diff expected.txt output.txt