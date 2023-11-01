/*
   Ryan Hirscher
   1/28/2021
   CSC-1720
   /home/students/rhirscher/csc1720/prog1/hirscherProg1A.cpp

   This is an A level program. Including features of counting vowels, words, sentences, and holding the highest number of words with the corresponding sentence number.
   This file is the main file that calls the methods of the class. It will read in characters from a file and count words, characters, and sentences. It also determines the highest number of words in a certain sentence.

   Compile: g++ -Wall hirscherProg1A.cpp counterType.cpp
   Execute: ./a.out
*/
//Libraries
#include <iomanip>
#include <string.h>
#include <cstring>
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include "counterType.h" //Include header file
using namespace std;

int main()
{
   char characters [250];
   string words [100];
   int maxWords = 0;
   counterType cntVowels;
   counterType cntX;
   counterType cntXTemp;
   counterType cntY;
   counterType cntSentences;
   counterType sNumber;
   counterType cntLongest;
   int length = 0;
   char converted[length+1]; //Array to convert string to C-string to read for "."
   string filename; //Input string for name of file
   ifstream myfile; //ifstream open file
   cout << "Please enter the name of the file. (Seuss.txt)" << endl; //Prompt for filename
   cin >> filename;
   myfile.open(filename);
   sNumber.setCounter(1); //Start on the first sentence
     while (!myfile.eof()) //Counts words of file and keeps track of white spaces with counter X.
   {
       myfile >> words[cntX.getCounter()]; //infile to words array at the instance of count X
       length = words[cntX.getCounter()].length(); //Length is equal to word at that instance
       strcpy(converted, words[cntX.getCounter()].c_str()); //Copy string of the word at that instance to c-string at that instance
       
       for (int t = 0; t<length; t++) //For as long as the word is
          if (converted[t] == '.') //If period increment Temp counter for max words
          {
             if (maxWords < cntXTemp.getCounter()) //Keep highest counter
             {
                maxWords = cntXTemp.getCounter(); //Holds max
                sNumber.incrementCounter(); //Increment which sentence
             }
             cntXTemp.setCounter(0);
          }
       cntX.incrementCounter();
       cntXTemp.incrementCounter();
   }
   cntLongest.setCounter(maxWords); //Pass maxWords to longest count
   cntX.decrementCounter(); //Subtract one because of extra
   myfile.close();
   myfile.open(filename); //Close and reopen file ro count characters (no white spaces)
     while (!myfile.eof())
   {
       myfile >> characters[cntY.getCounter()];
       //This next line checks  a character at this instant if it is a vowel
       if (characters[cntY.getCounter()] == 'a' || characters[cntY.getCounter()] == 'e' || characters[cntY.getCounter()] == 'i' || characters[cntY.getCounter()] == 'o' || characters[cntY.getCounter()] == 'u' || characters[cntY.getCounter()] == 'A' || characters[cntY.getCounter()] == 'E' || characters[cntY.getCounter()] == 'I' || characters[cntY.getCounter()] == 'O' || characters[cntY.getCounter()] == 'U')
          cntVowels.incrementCounter(); //Increment vowels
       if (characters[cntY.getCounter()] == '.')
          cntSentences.incrementCounter();
       cntY.incrementCounter(); //Else increment Y counter 
   }
   cout << endl << "Passage from Seuss.txt" << endl; //Title: formatted aligned
   cout << right << setw(28) << "Number of characters: " << cntX.getCounter()+cntY.getCounter() << endl; //Counter X and Y for character total including white space
   cout << right << setw(24) << "Number of vowels: ";
   cntVowels.displayCounter(); //Vowels
   cout << endl;
   cout << right << setw(27) << "Number of sentences: "; 
   cntSentences.displayCounter(); //Sentences counter
   cout << endl;
   cout << right << setw(33) << "Sentence with most words: #" << sNumber.getCounter()+1 << endl; //Number of sentences
   cout << right << setw(43) << "Number of words in longest sentence: " << cntLongest.getCounter() << endl;
   myfile.close(); //Close file peacefully
   
   return 0; //End
}
