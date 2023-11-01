/*
   Ryan Hirscher
   csc1720
   3/21/2021
   /home/students/rhirscher/csc1720/prog3/uniqueListType.cpp

   This file is the header file for the class uniqueListType that declares the class and it is derived from the base class arrayListType

   Compile and Execute instructions are in listMain.cpp
*/
#ifndef UnorderedArrayList_TYPE
#define UnorderedArrayList_TYPE
   
#include "arrayListType.h" 
#include <string>
template <class T>
class unorderedArrayListType: public arrayListType<T>
{
   using arrayListType<T>::maxSize;
   using arrayListType<T>::length;
   using arrayListType<T>::list;
   public:
      //Constructor
      unorderedArrayListType(int size = 100);

      /* insertAt Function to insert a string in a position according to the passed parameter. Then it shifts the numbers accordingly. The list will remain the same if it is at max size.
         Precondition: The string is not inputed and the list remains.
         Postcondition: The string is inputed in the position by parameter and the size is increased by 1.
      */
      void insertAt(int location, T insertItem);
  
      /* insertEnd Function to insert a string at the end of the list array and increasing the size by 1 as long as it's not exceeding.
         Precondition: The string is not inserted and list remains.
         Postcondition: The string is inserted at the end and list is expanded by 1 as long as it is not exceeding.
      */
      void insertEnd(T insertItem);

      /* replaceAt Function to replace a string in the list by position.
         Precondition: The string is not replaced by position and the list remains.
         Postcondition: The string passed by parameter has replaced the position passed by parameter.
      */
      void replaceAt(int location, T repItem);
  
      /* seqSearh Function to search the array for an item string passed by parameter.
         Precondition: The string has not been found nor has one been passed to search for.
         Postcondition: The string to search for has been found and returned a copy of that number.
      */
      int seqSearch(T searchItem) const;

}; 
#include "unorderedArrayListType.cpp"
#endif
