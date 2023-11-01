/*
   Ryan Hirscher
   /home/students/rhirscher/csc1720/prog4/powerMain.cpp
   3/30/3034
   csc1720

   This file is the main function file that uses recursive functions to make a power function. The program will prompt the user for values until one can be fully calculated and then the answer will print. Negative bases are not accepted. Negative powers are accepted. This is the 100% level program which makes sure the calculation does not exceed the memory capaticy of an integer value.

   Compile: g++ -Wall powerMain.cpp -o testProg
   Execute: ./testProg
*/
#include <iostream>
#include <cfloat>
#include <climits>
#include "invalidPower.h"
using namespace std;

/*
   function Repower is a templated function that returns T which is the answer to a power recursive power function. The return statement calls itself until the number is returned. If the number passes a the memory capacity of an integer the calculation haults and an error is thrown.
   precondition: The value is not calculated.
   postcondition: The value is calculated and used recursively until it returns the value.
*/
template <class T>
T Repower (T, T, long double);

int main() ///////////MAIN START/////////////////////
{
   double base, pow, answer=0;
   bool flag=false;
   long double b, p;
   long double overflow = 0;
   
   do //Do while answer overflows
   {
      do //Enter base number while it is less than 0
      {
         try //Try this while base number is less than 0
         {
            cout << "Please enter the base number:" << endl;
            cin >> base;
            b = base;

            if (base == 0) //Base zero with any power will be zero
            {
               cout << "answer: " << answer << endl;
               exit(1);
            }
            if (base < 0)
               throw invalidPower(); //Base cannot be negative
         }
         catch(invalidPower invalidPowerObj) //Catch for base
         {
            cout << "Message: " << invalidPowerObj.what() << endl;
         }

      }while(base < 0);

      try
      {
         flag = false; //Valid answer so far
         cout << "Please enter the power number: " << endl;
         cin >> pow;
         p = pow;

         overflow = Repower(b, p, overflow); //First calculation in long double
         answer =  Repower(base, pow, overflow); //Second calculation if passes
      }

      catch(invalidPower invalidPowerObj) //Catche for power
      {
         flag = true; //Invalid answer continue the loop
         cout << "Message: " << invalidPowerObj.what() << endl;
         overflow = 0; //Reset overflow cap
      }
   } while (flag); //Do this while answer does not overflow
   cout << "Answer: " << answer << endl;
   return 0;
} //END MAIN

/////////////////////////////FUNCTIONS//////////////////////////
template <class T> //Templating for double and long double
T Repower (T j, T k, long double overflowPass)
{
   if (k == 0)
      return 1;
   else if (k == 1)
   {
      
      if(overflowPass >= static_cast<long double>(INT_MAX)) //If the long double is bigger than int_max then it overflows end the calculation and re-enter base and power
         throw invalidPower(k); //Throwing error with parameter
      return j;
   }
   else
   {  
      if (k < 0)
         return (1/(j*Repower(j, (-k)-1, overflowPass))); //If power is negative switch. Recurisve calling itself.
      else
         return j*Repower(j, k-1, overflowPass); //If power is positive. Recursive calling itself.
   }
}
