#/bin/bash
# Ryan Hirscher
# CSC4510 Dr. Oudshoorn
# Assignment 1 -  Compare.sh Script
#
# This program will execute a program testing against expected results

if [ $# -ne 3 ]
then
   echo "How to: "
   echo "./Compare.sh [input directory] [executable] [test directory]"
   echo "Execute the script from the Script directory and do not specify any Paths."
   echo "[input directory] options: TestFiles"
   echo "[executable] suggested options: correctAdd (c++), correctadd (ada), incorrectAdd (c++), incorrectadd (ada)"
   echo "[test directory] options: Correct"
   exit 1;
fi

#Set and test args
input="../$1"
exe="../Source/$2"
tdir="../$3"

if [ ! -d "$input" ]
then
   echo "$input does not exist, or something happened to TestFiles which should be adjacent to the Script directory. Make sure you are in the Script directory."
   exit 3;
fi

if [ ! -e "$exe" ]
then
   echo "$exe does not exist in the Source directory which should be adjacent to the Script directory. Make sure you are in the Script directory."
   exit 4;
fi

if [ ! -d "$tdir" ]
then
   echo "$tdir does not exist, or something happened to Correct which should be adjacent to the Script directory. Make sure you are in the Script directory."
   exit 5;
fi

# Passed Input
echo "Compare.sh information:"
echo "+ + + + + + + + + + + + +"
echo "Passed comparison input checks."
echo "Input directory: $input"
echo "Executable name: $exe"
echo "+ + + + + + + + + + + + +"
echo ""
# Call Test.sh
./Test.sh $1 $2
echo "Testing..."
tmp="./tmp"
if [ ! -d "$tmp" ]
then
   echo "Something went wrong executing Test.sh and tmp was not created."
   exit 3;
fi

# PRE: err#.out files may exist from previous runs
# Remove the diff output files if they exist
# POST: No err#.out files in tmp directory
rm ${tmp}/err* 2> /dev/null
err="false"

lstmp=(`ls $tmp`)
lscor=(`ls $tdir`)
if [ ${#lstmp[@]} -ne ${#lscor[@]} ]
then
   echo "Number of files in Correct and tmp are not equal."
   exit 7;
fi

# PRE: Iterate through the list assuming tmp and Correct are the same size and there are no error files
# Append any differences to tmp directory
# Standard out log which individual cases break
# POST: cat the total differences of the err.out file after
index=0
while [ $index -lt ${#lscor[@]} ]
do
   diff ./tmp/${lstmp[$index]} ../Correct/${lscor[$index]} >> "${tmp}/err${index}.out"
   if [ -s "${tmp}/err${index}.out" ]
   then
      echo "TEST FAILED AT ../Correct/${lscor[$index]}"
      echo "--END TEST ${index}--" >> "${tmp}/err${index}.out"
      echo "" >> "${tmp}/err${index}.out"
      err="true"
   else
      echo "Passed ../Correct/${lscor[$index]}"
   fi
   index=`expr $index + 1`
done

# If there error flag is true, print each difference
# Otherwise all test cases passed
if [ "${err}" = "true" ]
then
   ind=0
   lserr=(`ls $tmp | grep err`)
   upper=${#lserr[@]}
   while [ $ind -lt $upper ]
   do
      cat $tmp/${lserr[$ind]}
      ind=`expr $ind + 1`
   done
else
   echo "Passed all cases."
fi
exit 12;

