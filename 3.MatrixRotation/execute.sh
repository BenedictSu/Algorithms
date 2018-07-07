#!/bin/bash
g++ -g MatrixRotation.cpp -o MatrixRotation
./MatrixRotation < input.txt > output.txt
diff expected.txt output.txt