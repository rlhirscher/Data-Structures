/*
   Ryan Hirscher
   csc1720
   3/21/2021
   /home/students/rhirscher/csc1720/prog3/uniqueListType.h

   This is the headerfile for the derived class uniqueListType of the class unorderedArrayListType

   Compile and execute instructions are in listMain.cpp
*/
#ifndef uniqueListType_TYPE
#define uniqueListType_TYPE
#include "unorderedArrayListType.h"
#include <string>

template <class T>
class uniqueListType: public unorderedArrayListType<T>
{
   using unorderedArrayListType<T>::seqSearch;
   public:

      /* uniqueListType: this is the constructor that invokes the constructor of unorderedArrayListType
         precondition: Object cannot be initialized
         postcondition: Object initialized
      */
      uniqueListType(int size = 100);

      /* insertAt: This is the overrided method of inserAt in
                   unorderedArrayListType. It then calls seqSearch which
                   searches the list for duplicate names and then inserts if
                   it is not found.
         precondition: List is not upadated with names not duplicated.
         postcondition: List is updated with names not duplicated.
      */
      void insertAt(int location, T insertItem);

      /* insertEnd: This is the overrided method of insertEnd in
                    unorderedArrayListType. It then calls seqSearch which
                    searches the list for duplicate names and then inserts if
                    it is not found.
         precondition: List is not upadated with names not duplicated.
         postcondition: List is updated with names not duplicated.
      */
      void insertEnd(T insertItem);

      /* replaceAt: This is the overrided method of replaceAt in
                    unorderedArrayListType. It then calls seqSearch which
                    searches the list for duplicate names and then replaces if
                    it is not found.
         precondition: List is not upadated with names not duplicated.
         postcondition: List is updated with names not duplicated.
      */
      void replaceAt(int location, T repItem);
};
#include "uniqueListType.cpp"
#endif
