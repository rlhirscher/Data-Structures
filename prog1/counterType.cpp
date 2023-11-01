
/*
   Ryan Hirscher
   1/28/2021
   home/students/rhirscher/csc1720/prog1/counterType.cpp
   This file is the implementation file which follows the home/students/rhirscher/csc1720/lab2/counterType.h
   
   This file contains the method functions that refer to main which passes values and uses the class counterType which is declared in the header file.
*/
#include"counterType.h" //This connects to the headerfile with the class definition
#include<iostream> //Libraries
using namespace std;
/*
   Pre-condition: object not initialized
   Post-condition: object initialized (set to zero) memory allocated
*/
void counterType::initializeCounter() //Class initializeCounter sets counter to 0
{
   counter = 0; //Initial counter
}

/*
   Pre-condition: object not set, but initialized
   Post-condition: counter is set to parameter and if it is negative set to zero
*/
void counterType::setCounter(int x) //Class setCounter passes value from main x and sets 0
{
   if (x >= 0) //If above zero set equal to passed value
      counter = x; //Equal to value in main
   else
      counter = 0; //If it's below zero then set to 0
}

/*
   Pre-condition: counter is not returned to main
   Post-condition: counter is back in main
*/
int counterType::getCounter() const //Class getCounter Receive the counter
{
   return counter; //Return the counter to main
}

/*
   Pre-condition: counter is not incremented
   Post-condition: counter is incremented
*/
void counterType::incrementCounter() //Class counterType Increment
{
   counter++; //Add one to counter
}

/*
   Pre-condition: counter is not decremented
   Post-condition: counter is decremented
*/
void counterType::decrementCounter() //Class counterType Decrement
{
   counter--; //Subtract one from counter
   if (counter <= 0) //If the counter is below zero
      counter = 0; //Set to zero
}

/*
   Pre-condition: count completed nothing displayed
   Post-condition: displayed
*/
void counterType::displayCounter() const //Will not change const Display
{
   cout << counter; //Output the count
}

/*
   Pre-condition: Not passed to parameterized constructor
   Post-condition: If negative set to zero otherwize set to parameter
*/
counterType::counterType (int x) //Class counterType parameter constructor which passes x from main
{
   if (x >= 0) //If the passed value from main is greater than 0 then set passed value to x
      counter = x;
   else
      counter = 0; //Else set to 0
}
/*
   Pre-condition: Not passed to constructor
   Post-condition: counter is set to zero 
*/
counterType::counterType() //Class default constructor if no value is passed
{
   counter = 0; //Set to 0
}



