/*
   Ryan Hirscher
   1/28/2021
   CSC-1720
   home/students/rhirscher/csc1720/prog1/counterType.h
   This file is the header file for home/students/rhirscher/csc1720/prog1/hirscherProg1A.cpp

   This declares the class counterType which global and will be used for main. No memory is allocated.
   Compile and execute instructions are in hirscherProg1A.cpp
*/
#ifndef COUNTER_TYPE
#define COUNTER_TYPE
class counterType //Class counterType for main
{
   public: //Public methods declaration
/*
   This takes the counter and initilizes it
   pre-condition: The counter is not initialized
   post-condition: Counter initialized
*/
      void initializeCounter();
/*
   This method sets the counter passed in from main or automatically sets to zero if nothing is passed
   pre-condition: no value passed or called to set value
   post-condition: Value is set to passed number or 0 if nothing
*/
      void setCounter(int =0); //If no value is entered it will be 0
/*
   This method returns the number to main which is held here.
   pre-condition: a number is held
   post-condition: the number has been called back to main
*/
      int getCounter() const; //Will not change
/*
   This method increments counter
   pre-condition: counter is not incremented
   post-condition: counter adds one
*/
      void incrementCounter();
/*
   This method decrements counter
   pre-condition: counter is not decremented
   post-condition: counter subtracts one
*/
      void decrementCounter();
/*
   This method outputs the counter
   pre-condition: counter is not outputted
   post-condition: counter is outputted
*/
      void displayCounter() const; //Will not change
/*
   This method is parameterized constructor that holds defaults with parameters
   pre-condition: parameterized information is void
   post-condition: parameterized defaults are saved and holds a position
*/
      counterType(int); //This method will be passed an integer or else the other constructor
/*
   This method is the default constructor for no parameters
   pre-condition: no position is held for no parameterized information
   post-condition: a position is held for information for defaults
*/
      counterType();
   private: //Private data declaration
      int counter; //Count
};
#endif //End
