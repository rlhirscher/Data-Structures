#ifndef UNORDEREDLINKEDLIST
#define UNORDEREDLINKEDLIST

#include "linkedList.h"

using namespace std;


//***************** derived unordered linked list type definition **************************
template <class Type>
class unorderedLinkedList:public linkedListType<Type>
{
public:
      bool search(const Type& searchItem) const;
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the 
      //               list, otherwise the value false is 
      //               returned.

      void insertFirst(const Type& newItem);
      //Function to insert newItem at the beginning of the list.
      //Postcondition: first points to the new list, newItem is
      //               inserted at the beginning of the list,
      //               last points to the last node in the  
      //               list, and count is incremented by 1.

      void insertLast(const Type& newItem);
      //Function to insert newItem at the end of the list.
      //Postcondition: first points to the new list, newItem 
      //               is inserted at the end of the list,
      //               last points to the last node in the 
      //               list, and count is incremented by 1.

      void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing 
      //               deleteItem is deleted from the list.
      //               first points to the first node, last
      //               points to the last node of the updated 
      //               list, and count is decremented by 1.
      void deleteLargest();
      //Function to delete the largest item from the list.
      //Postcondition: The largest element in the list is
      //               found and then deleted from the linked
      //               list.
      void merge(unorderedLinkedList<Type> &secondListPass);

};

//***************** unordered linked list type implementation **************************

template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const
{
   nodeType<Type> *curPtr = this->first;

   while(curPtr != nullptr) {
      if(curPtr->info == searchItem)
         return true;
      curPtr = curPtr->link;
   }

   return false;
}

template <class Type>
void unorderedLinkedList<Type>::merge(unorderedLinkedList<Type> &secondListPass)
{
   if (this->isEmpty() && secondListPass.isEmpty())
   {
      cerr << "Both lists are empty!";
   }
   else if (this->isEmpty() && !secondListPass.isEmpty())
   {
      this->first = secondListPass.first;
      this->count = secondListPass.count;
      this->last = secondListPass.last;
      secondListPass.first = nullptr;
      secondListPass.last = nullptr;
      secondListPass.count = 0;
   }
   else if (!this->isEmpty() && secondListPass.isEmpty())
   {
      cerr << "(Nothing to merge into the list!) ";
   }
   else
   {
      this->last->link = secondListPass.first;
      secondListPass.first = nullptr;
      this->last = secondListPass.last;
      secondListPass.last = nullptr;
      this->count += secondListPass.count;
      secondListPass.count = 0;
   }
}

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type & newItem)
{
   nodeType<Type> *newNode;
   newNode = new nodeType<Type>;
   newNode->info = newItem;
   newNode->link = this->first;
   this->first = newNode;
   this->count++;

   if(this->last==nullptr)
      this->last = newNode;
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type & newItem)
{
   nodeType<Type> *newNode;
   newNode = new nodeType<Type>;
   newNode->info = newItem;
   this->count++;

   if(this->last==nullptr)
      this->first = this->last = newNode;
   else {
      this->last->link = newNode;
      this->last = newNode; 
   }
}

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
   nodeType<Type> *curPtr;
   nodeType<Type> *prevPtr;
   bool found = false;
  
   if(this->isEmpty())
      cerr << "List is empty, can't delete from empty list!" << endl;
   else {
      prevPtr = nullptr;
      curPtr = this->first;
      while(curPtr != nullptr && !found) {
         if(curPtr->info != deleteItem) {
            prevPtr = curPtr;
            curPtr = curPtr->link;
         } else {
            found = true;
         }
      }
      if(!found) {
         cerr << deleteItem << " is not in the list" << endl;
      } else {
         if(curPtr == this->first) {
            //found in the first node
            this->first = this->first->link;
         } else {
            //found after the first node 
            prevPtr->link = curPtr->link;
         }
         if(curPtr == this->last) {
            //if curPtr = last pointer then one of two items are true;
            //only one node in the list and deleteItem is in the first node
            //more than one node in the list and deleteItem is the last node
            this->last = prevPtr;
         }
         delete curPtr; 
         this->count--;
      }
   }

}

template <class Type>
void unorderedLinkedList<Type>::deleteLargest()
{
   nodeType<Type> *curPtr; //Current pointer
   Type max = 0;
   if(this->isEmpty())
      cerr << "List is empty, can't delete from empty list!" << endl;
   else
   {
      curPtr = this->first; //Pointing to the first
      while(curPtr != nullptr) //While the current pointer is pointing to something other than nullptr
      {
         if(max < curPtr->info) //If max is less than the new item
            max = curPtr->info; //set max equal to the new largest item
         else
         {
            curPtr = curPtr->link; //Continue down the list
         }
      }
      unorderedLinkedList<Type>::deleteNode(max); //Calling deleteNode and passing the max to delete it
   } 
}

#endif
