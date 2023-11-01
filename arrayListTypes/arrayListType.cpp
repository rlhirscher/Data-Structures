/*
   Ryan Hirscher
   csc1720
   /home/students/rhirscher/csc1720/prog3/arrayListType.cpp
   3/21/2021

   This file is the implementation file for the base class that defines its methods.

   Compile and execute instructions are in listMain.cpp
*/
#include <iostream> 
#include <string> 
using namespace std;

template <class T>
arrayListType<T>::arrayListType(int size)
{
   if (size <= 0)
   {
      cout << "The array size must be positive. Creating "
           << "an array of the size 100." << endl;

      maxSize = 100;
   }
   else
      maxSize = size;

   length = 0;

   list = new T[maxSize];
} //end constructor

template <class T>
arrayListType<T>::~arrayListType()
{
   delete [] list;
} //end destructor

template <class T>
T arrayListType<T>::getAt(int pos)
{
   T winner;
   winner = list[pos];
   return winner;
}

template <class T>
arrayListType<T>::arrayListType(const arrayListType<T> &otherList)
{
   maxSize = otherList.maxSize;
   length = otherList.length;

   list = new T[maxSize]; 	//create the array

   for (int j = 0; j < length; j++)  //copy otherList
      list[j] = otherList.list[j];
}//end copy constructor

template <class T>
bool arrayListType<T>::isEmpty() const
{
   return (length == 0);
} //end isEmpty

template <class T>
bool arrayListType<T>::isFull() const  
{
   return (length == maxSize);
} //end isFull

template <class T>
int arrayListType<T>::listSize() const
{
   return length;
} //end listSize

template <class T>
int arrayListType<T>::maxListSize() const
{
   return maxSize;
} //end maxListSize

template <class T>
void arrayListType<T>::print() const
{
   for (int i = 0; i < length; i++)
      cout << list[i] << " ";
   cout << endl;
} //end print

template <class T>
void arrayListType<T>::removeAt(int location)
{
   if (location < 0 || location >= length)
      cout << "The location of the item to be removed "
           << "is out of range." << endl;
   else
   {
      for (int i = location; i < length - 1; i++)
         list[i] = list[i+1];

      length--;
   }
} //end removeAt

template <class T>
void arrayListType<T>::clearList()
{
   length = 0;
} //end clearList
