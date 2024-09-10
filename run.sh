# chmod +x run.sh
# ./run.sh 1.cpp

#!/bin/bash
file="$1"
outputFile="${file%.*}"
inputFile="${file%.*}.in"

g++ -g "$file" -o "$outputFile" -O2 -DONLINE_JUDGE -std=c++11 && ./"$outputFile" < "$inputFile"
