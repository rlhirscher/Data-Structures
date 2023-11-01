/*
   Ryan Hirscher
   csc1720
   3/30/2021
   /home/students/rhirscher/csc1720/prog4/overflowException.h

   This is the headerfile user defined exception handling class that validates user input to make sure an answer does not overflow the memory of an int.

   Compile and Execute instructions are in main.
*/
#include <iostream>
#include <string>
#ifndef INVALIDPOWER_TYPE
#define INVALIDPOWER_TYPE
using namespace std;
class invalidPower
{
   public: 
      invalidPower()//Error for base
      {
         error = "The base must be positive.";
      }
      invalidPower(double pass) //Error for power
      {
         error = "The answer overflows the memory of an integer.";
      }
      string what()
      {
         return error;
      }
   private:
      string error; 
};
#endif
