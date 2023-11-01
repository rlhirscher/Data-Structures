#!/bin/bash
# Ryan Hirscher
# CSC4510 Dr. Oudshoorn
# Assignment 1 - Test.sh Script
#
# This program will execute a program testing against a test suite

if [ $# -ne 2 ]
then
   echo "How to: "
   echo "./Test.sh [input directory] [executable]"
   echo "Execute the script from the Script directory and do not specify any Paths."
   echo "[input directory] options: TestFiles"
   echo "[executable] options: correctAdd (c++), correctadd (ada), incorrectAdd (c++), incorrectadd (ada)"
   exit 2;
fi

# Set and test args
input="../$1"
exe="../Source/$2"

if [ ! -d "$input" ]
then
   echo "$input does not exist, or something happened to TestFiles which should be adjacent to the Script directory. Make sure you are in the Script directory."
   exit 2;
fi

if [ ! -e "$exe" ]
then
   echo "$exe does not exist in the Source directory which should be adjacent to the Script directory. Make sure you are in the Script directory."
   exit 2;
fi

# Passed Input
echo "Test.sh information:"
echo "+ + + + + + + + + + + + +"
echo "Passed runtime input checks."
echo "Input directory: $input"
echo "Executable name: $exe"
# Create tmp directory to store the output
# If the tmp exists, remove it and everything inside
tmp="./tmp"
if [ -d "$tmp" ]
then
   rm -rf "$tmp"
fi

# New tmp directory
mkdir "$tmp"

if [ ! -d "$tmp" ]
then
   echo "tmp directory was not created."
   exit 2;
fi

# Store the ls of the test directory then iterate through the array and execute with I/O
index=0
lsfiles=(`ls $input`)
upper="$(ls $input | wc -l)"
while [ $index -lt $upper ]
do
   $exe < "$input/${lsfiles[$index]}" > "$tmp/${lsfiles[$index]}.out"
   index=`expr $index + 1`
done
echo "Program output: $tmp"
echo "+ + + + + + + + + + + + +"
echo ""
exit 11;

