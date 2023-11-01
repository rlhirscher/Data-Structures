#!/bin/bash
# Ryan Hirscher
# CSC4510 Dr. Oudshoorn
# Assignment 1 - Sum.sh script
#
# Compile, Test, and Compare by invoking each script in order


if [ $# -ne 5 ]
then
   echo "How to: "
   echo "./Sum.sh [language] [sourcefile] [input directory] [executable] [test directory]"
   echo "Execute the script from the Script directory and do not specify any Paths."
   echo "[language] options: cpp and ada"
   echo "[sourcefile] options: correctAdd.cpp, correctadd.adb, incorrectAdd.cpp, incorrectadd.adb"
   echo "[input directory] options: TestFiles"
   echo "[executable] suggested options: correctAdd (c++), correctadd (ada), incorrectAdd (c++), incorrectadd (ada)"
   echo "[test directory] options: Correct"
   exit 1;
fi

# Run scripts
# POST: if a script exit code is not 10, 11, 12 Then improper usage.
./Compile.sh ${1} ${2} ${4}
catch=$?
if [ $catch != "10" ]
then
   echo "----------------"
   echo "Compile failure."
   echo "----------------"
   exit 2;
fi

# Exit 12 is successful completion of Compare.sh
# Exit 3 is Test.sh failure
./Compare.sh $3 $4 $5
catch=$?
if [ $catch != "12" ]
then
   if [ $catch = "3" ]
   then
      echo "----------------"
      echo "Runtime failure."
      echo "----------------"
   else
      echo "-------------------"
      echo "Comparison failure."
      echo "-------------------"
      exit 4;
   fi
fi
exit 6;
