#!/bin/bash
# Ryan Hirscher
# CSC4510 Dr. Oudshoorn
# Assignment 1 - Compile.sh Script
#
# This program Compiles a specified program

#If there are not exactly 3 arguments, send useage statement
if [ $# -ne 3 ]
then
   echo "How to: "
   echo "./Compile.sh [language] [sourcefile] [executable]"
   echo "Execute the script from the Script directory and do not specify Path."
   echo "[language] options: cpp and ada" 
   echo "[sourcefile] options: correctAdd.cpp, correctadd.adb, incorrectAdd.cpp, incorrectadd.adb"
   echo "[executable] suggested options: correctAdd (c++), correctadd (ada), incorrectAdd (c++), incorrectadd (ada)"
   exit 1;
fi

# Set and test args
# Set supporting languages
clang="cpp"
alang="ada"
lang=$1
src="../Source/$2"
exe=$3

if [ "$lang" != "$clang" ] && [ "$lang" != "$alang" ]
then
   echo "$lang is not a supported language."
   echo "[language] options: cpp and ada"
   exit 2;
fi

if [ ! -e "$src" ]
then
   echo "Source file does not exist at $src"
   exit 3;
fi

# Passed Input
echo "Compile.sh information:"
echo "+ + + + + + + + + + + + +"
echo "Passed Compile input checks."
echo "Language: $lang"
echo "Source file: $src"
echo "Executable name: ../Source/$exe"
echo "+ + + + + + + + + + + + +"
echo ""

# Set compiler
if [ "$lang" = "$clang" ]
then
   comp="g++"
else
   comp="gnatmake"
fi

# If the source file is a .cpp extension and trying to compile with ada, fail and throw usage
# Same for .ada source and cpp compiler
if [[ "$src" = *".cpp" ]] && [[ "$lang" = "$alang" ]]
then
   echo "$src is not supported by ada."
   echo "Terminating."
   exit 2;
else if [[ "$src" = *".adb" ]] && [[ "$lang" = "$clang" ]]
   then 
      echo "$src is not supported by c++."
      echo "Terminating."
      exit 2;
   fi
fi
$comp $src -o ../Source/$exe
exit 10;
