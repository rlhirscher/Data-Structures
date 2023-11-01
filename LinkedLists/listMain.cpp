/*
   Ryan Hirscher
   csc1720
   /home/students/rhirscher/csc1720/prog5/listMain.cpp
   4/28/2021

   This program takes two unordered lists of information and merges them into an ordered list according to the GPA of a class stuType. stuType must overload several operators to preform actions based off of GPA. This program prints the list of students and their GPA in descending order. Then the average is calcuated of all the GPAs. This program tests the functionality of the merge and conditions of the lists. This program also tests the functionality of the dataType stuType that stores first name, last name, and GPA.  

   Compile: g++ -Wall  listMain.cpp -o testProg
   Execute: ./testProg

*/
#include <iostream>
#include <fstream>
#include "linkedList.h"
#include "orderedLinkedList.h"
#include "unorderedLinkedList.h"
#include "studentType.h"
//Function load takes an orderedLinkedList<Type> by reference and a string of
//         of the filename. It opens the file and is ready to
//         load stuType bundles into a linked list that is ordered
//         Postcondition: A list is loaded by order into a list object by links
template <class Type>
void load (orderedLinkedList<Type>&, string);

//Function findAverage to find the average of an orderedLinkedList<Type>
//         by using the iterator class to move through the linked list
//         effectively.
//         Postcondition: The average is calculated iteratively and returned to main
template <class Type>
double findAverage (orderedLinkedList<Type>&);
using namespace std;

int main()
{
///////////////////////////////////// INSTANTIATE AND PROMPT FOR FILES///////////////
   orderedLinkedList<stuType> listA;
   orderedLinkedList<stuType> listB;
   string filenameOne, filenameTwo;
   double avg = 0;
   cout << "Please enter the first filename: ('data1'): " << endl;
   cin >> filenameOne;
   cout << "Please enter the second filename: ('data2'): " << endl;
   cin >> filenameTwo;
   load(listA, filenameOne); //load each
   load(listB, filenameTwo);
   cout << endl << endl << "***FIRST LIST***" << endl; //Print original lists
   listA.feederPrintR();
   cout << endl << "***SECOND LIST***" << endl;
   listB.feederPrintR();

/////////////////////////////////////////////////////////////////////////////////////
//////////////////// MERGE TESTS AND REVERSE RECURSIVE PRINT/////////////////////////
   cout << endl << endl << "**** MERGING THE ORDERED LISTS FROM LIST B INTO LIST A ****" << endl; //B->A
   listA.merge(listB);
   cout << endl << endl << "***FIRST LIST***" << endl;
   listA.feederPrintR();
   cout << endl << "***SECOND LIST***" << endl;
   listB.feederPrintR();

   cout << endl << endl << "**** MERGING THE ORDERED LISTS FROM LIST B INTO LIST A ****" << endl; //B->A
   listA.merge(listB);
   cout << endl << endl << "***FIRST LIST***" << endl;
   listA.feederPrintR();
   cout << endl << "***SECOND LIST***" << endl;
   listB.feederPrintR();

   cout << endl << endl << "**** MERGING THE ORDERED LISTS FROM LIST A INTO LIST B ****" << endl; //A->B
   listB.merge(listA);
   cout << endl << endl << "***FIRST LIST***" << endl;
   listA.feederPrintR();
   cout << endl << "***SECOND LIST***" << endl;
   listB.feederPrintR();

   cout << endl << endl << "**** MERGING THE ORDERED LISTS FROM LIST A INTO LIST B ****" << endl; //A->B
   listB.merge(listA);
   cout << endl << endl << "***FIRST LIST***" << endl;
   listA.feederPrintR();
   cout << endl << "***SECOND LIST***" << endl;
   listB.feederPrintR();
   avg = findAverage(listB);//Calling average

   listB.listKiller(); //Killing the list

   cout << endl << endl << "**** KILLING THE LISTS ****" << endl;
   cout << endl << endl << "***FIRST LIST***" << endl;
   listA.feederPrintR();
   cout << endl << "***SECOND LIST***" << endl;
   listB.feederPrintR();

   cout << endl << endl << "**** MERGING THE ORDERED LISTS FROM LIST A INTO LIST B ****" << endl; //A->B
   listB.merge(listA);
   cout << endl << endl << "***FIRST LIST***" << endl;
   listA.feederPrintR();
   cout << endl << "***SECOND LIST***" << endl;
   listB.feederPrintR();


/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// FIND AVERAGE /////////////////////////////////
   cout << endl << endl << "*** AVERAGE OF ALL GPAs BEFORE DELETED***" << endl;
   cout << "Average GPA: " << avg << endl;
   return 0;
}//End main

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// FUNCTIONS ///////////////////////////////////
template <class Type> //Load function
void load (orderedLinkedList<Type> &listPass, string filenamePass)
{
   double tempGPA = 0; //Used for GPA
   string tempWord; //Used for first and last - Overwritten
   stuType temp; //Used for bundle
   ifstream inFile;
   inFile.open(filenamePass);
   inFile >> tempWord; 
   temp.setFirst(tempWord); //Setting
   inFile >> tempWord;
   temp.setLast(tempWord); //Setting
   inFile >> tempGPA; 
   temp.setGPA(tempGPA); //Setting

   while (!inFile.eof()) //Repeat
   {
      listPass.insert(temp);
      inFile >> tempWord; 
      temp.setFirst(tempWord);
      inFile >> tempWord;
      temp.setLast(tempWord);
      inFile >> tempGPA; 
      temp.setGPA(tempGPA);  
   }
   inFile.close();
}

template <class Type> //Function find average
double findAverage(orderedLinkedList<Type> &list)
{
   double sum = 0; 
   linkedListIterator<stuType> it;
   for (it = list.begin(); it != list.end(); ++it) 
   {
      sum += (*it).getGPA(); //Sum is equal to it dereferenecd and applying the getGPA
   } 
   return sum/list.length();
}
//////////////////////////////////////////////////////// END ///////////////////////////
