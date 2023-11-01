/*
   Ryan Hirscher
   csc1720
   3/21/2021
   /home/students/rhirscher/csc1720/prog3/uniqueListType.cpp

   This file is the implementation file for the derived class uniqueListType of the class unorderedArrayListType

   Compile and Execute instructions are in listMain.cpp
*/
#include <string>
using namespace std;
//Constructor calls unorderedArrayListType constructor

template <class T>
uniqueListType<T>::uniqueListType(int size)
: unorderedArrayListType<T>(size)
{
}//End constructor

template <class T>
void uniqueListType<T>::insertAt(int location, T insertItem)
{
   if (seqSearch(insertItem) == -1) //If seqSearch returns -1 or "not found"
      unorderedArrayListType<T>::insertAt(location, insertItem); //Then insert according to location
}

template <class T>
void uniqueListType<T>::insertEnd(T insertItem)
{
   if (seqSearch(insertItem) == -1) //If seqSearch returns -1 or "not found"
      unorderedArrayListType<T>::insertEnd(insertItem); //Then insert at the end
}

template <class T>
void uniqueListType<T>::replaceAt(int location, T repItem)
{
   if (seqSearch(repItem) == -1) //If seqSearch returns -1 or "not found"
      unorderedArrayListType<T>::replaceAt(location, repItem); //Then replace at location
}
