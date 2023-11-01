/*
   Ryan, Will, Collin, and Michael
   12/8/2021
   /home/students/rhirscher/csc2710/programs/projectThree/hashAlg.cpp
   Dr. Williams CSC 2710   
   
   Compile: g++ hashAlg.cpp -o testProg
   Execution: ./testProg

   This program simulates the sending of a file where the meta data of the file being sent is put through a hashing algorithm before the file is 'sent' and after it has been 'received.' If the hash output of the intial meta data and the final meta data equal each other then the file was sent successfully. If the hash output does not match then the file had been edited or corrupted.

*/
#include <iostream>
#include <functional>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
int main()
{
//////////////// DECLARATION /////////////////////////////////////////////

   hash<string> str_hash; //Hash for string type
   string filename;
   fstream inFile;
   string initial_h;
   string final_h;
   const char* build_ptr; //System executable
   string build;

//////////////////////////////////////////////////////////////////////////
//////////////////////// PROMPT //////////////////////////////////////////

   system("rm meta.txt >nul 2>nul"); //if it doesn't exists it will not output error
   cout << "hashAlg.cpp: Enter the send filename: ";
   cin >> filename;

//////////////////////////////////////////////////////////////////////////
///////////////////////// CHECK FILE /////////////////////////////////////

   inFile.open(filename);
   if (inFile.is_open() == false)
   {
      cout << "File does not exist. Exiting." << endl;
      exit(1);
   }

   inFile.close();

//////////////////////////////////////////////////////////////////////////
/////////////// READING META DATA 1 //////////////////////////////////////

   build = "ls -l " + filename + " > meta.txt"; //String buffer with filename
   build_ptr = build.c_str();
   system(build_ptr);
   inFile.open("meta.txt");
   getline(inFile, initial_h);
   cout << "hashAlg.cpp: Sending..." << endl;
   inFile.close();
   system("rm meta.txt");
   system("sleep 10s"); //SIMULATING SENDING
   cout << "hashAlg.cpp: Received." << endl;

//////////////////////////////////////////////////////////////////////////
///////////// READING META DATA 2/////////////////////////////////////////

   system(build_ptr);
   inFile.open("meta.txt");
   getline(inFile, final_h);
   system("rm meta.txt");
   cout << "hashAlg.cpp: (Initial) " << str_hash(initial_h) << endl;
   cout << "hashAlg.cpp: (Final) " << str_hash(final_h) << endl;

//////////////////////////////////////////////////////////////////////////
///////////////////// CHECK HASH SUM /////////////////////////////////////

   if (str_hash(initial_h) == str_hash(final_h))
      cout << "hashAlg.cpp: The file is unedited and not corrupted. Successful." << endl;
   else
      cout << "hashAlg.cpp: The file was corrupted or edited. Failed." << endl;

   return 0;
}

