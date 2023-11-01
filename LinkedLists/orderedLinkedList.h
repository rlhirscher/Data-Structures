#ifndef ORDEREDLINKEDLIST
#define ORDEREDLINKEDLIST

#include "linkedList.h"

using namespace std;


//***************** derived ordered linked list type definition **************************
template <class Type>
class orderedLinkedList:public linkedListType<Type>
{
public:

    void merge(orderedLinkedList<Type>&);
      //Function merge to determine the condition of the 2 lists
      //               and then to merge them together while
      //               maintaining the order.
      //Postcondition: Lists are merged together into the caller
      //               object.

    bool search(const Type& searchItem) const;
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the list, 
      //               otherwise the value false is returned.

    void insert(const Type& newItem);
      //Function to insert newItem in the list.
      //Postcondition: first points to the new list, newItem 
      //               is inserted at the proper place in the
      //               list, and count is incremented by 1.

    void insertFirst(const Type& newItem);
      //Function to insert newItem at the beginning of the list.
      //Postcondition: first points to the new list, newItem is
      //               inserted at the proper place in the list,
      //               last points to the last node in the  
      //               list, and count is incremented by 1.

    void insertLast(const Type& newItem);
      //Function to insert newItem at the end of the list.
      //Postcondition: first points to the new list, newItem is 
      //               inserted at the proper place in the list,
      //               last points to the last node in the 
      //               list, and count is incremented by 1.

    void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing 
      //               deleteItem is deleted from the list;
      //               first points to the first node of the 
      //               new list, and count is decremented by 1.
      //               If deleteItem is not in the list, an
      //               appropriate message is printed.
    void deleteLargest();
      //Function to delete the largest item in the linked list.
      //Postcondition: When found (the last item in the list) 
      //               the function will delete that item
      //               from the linked list.
};


//***************** ordered linked list type implementation **************************

template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const
{
   nodeType<Type> *curPtr = this->first;
   //items in the list are in ascending order.
   //stop when you find it and return true.
   //stop when you know it's not in the list because
   //we have advanced to info larger than the searchItem
   while(curPtr != nullptr) {
      if(curPtr->info == searchItem)
         return true;  
      else if(curPtr->info > searchItem)
         return false;  
      curPtr = curPtr->link;
   }
   //at the end of the list so not present.
   return false;
}
template <class Type>
void orderedLinkedList<Type>::merge(orderedLinkedList<Type>& other)
{
   if(this->isEmpty() && other.isEmpty()) //If both lists are empty
   {
      cerr << "(Both lists are empty!)";
   }
   else if(this->isEmpty() && !other.isEmpty()) //If caller list is empty
   {
      this->first = other.first;
      this->count = other.count;
      this->last = other.last;
      other.first = nullptr;
      other.last = nullptr;
      other.count = 0;
   }
   else if(!this->isEmpty() && other.isEmpty()) //If both empty
   {
      cerr << "(Nothing to merge into the list!)";
   }
   else //Assuming both lists have elements
   {
      nodeType<Type> *cur; //Current pointer
      orderedLinkedList<Type> list; //A new list
      nodeType<Type> *fPtr = this->first; //Assign
      nodeType<Type> *pPtr = other.first;
      if(fPtr->info < pPtr->info) //Determine which is greater
      {
         list.first = fPtr;
         fPtr = fPtr->link;
      }   
      else
      {
         list.first = pPtr;
         pPtr = pPtr->link;
      }
      cur = list.first;
      while(fPtr != nullptr && pPtr != nullptr) //Continue until the exhuasted
      {
         if(fPtr->info < pPtr->info)
         {
            cur->link = fPtr; //Swap and continue
            fPtr = fPtr->link;
            cur = cur->link;
         }
         else
         {
            cur->link = pPtr;
            pPtr = pPtr->link;
            cur = cur->link;
         }
      }
      if(fPtr != nullptr)
      {
         cur->link = fPtr;
         list.last = this->last;
      }
      else
      {
         cur->link = pPtr;
         list.last = other.last;
      }
      this->first = list.first; //Adjust lists appropriately
      this->last = list.last;
      list.first = nullptr;
      list.last = nullptr;
      this->count += other.count;
      list.count = 0;
      other.first = nullptr;
      other.last = nullptr;
      other.count = 0;
   }  
}
template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
   nodeType<Type> *curPtr;
   nodeType<Type> *prevPtr;
   nodeType<Type> *newNode;

   newNode = new nodeType<Type>;
   newNode->info = newItem;
   newNode->link = nullptr;

   if(this->isEmpty()) {
      this->first = this->last = newNode;
   } else {
      prevPtr = nullptr;
      curPtr = this->first;
      while(curPtr != nullptr && curPtr->info < newItem) {
         prevPtr = curPtr;
         curPtr = curPtr->link;
      }
      if(curPtr == this->first) {
         //add as a new first node
         newNode->link = this->first;
         this->first = newNode;
      } else {
         //found after the first node 
         prevPtr->link = newNode;
         newNode->link = curPtr;
         if(prevPtr == this->last) {
            this->last = newNode;
         }
      }
   }
   this->count++;
}

template <class Type>
void orderedLinkedList<Type>::insertFirst(const Type & newItem)
{
   insert(newItem);
}

template <class Type>
void orderedLinkedList<Type>::insertLast(const Type & newItem)
{
   insert(newItem);
}

template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
   nodeType<Type> *curPtr;
   nodeType<Type> *prevPtr;
   
   if(this->isEmpty())
      cerr << "List is empty, can't delete from empty list!" << endl;
   else {
      prevPtr = nullptr;
      curPtr = this->first;
      //move down list until you find it or the info is
      //larger than deleteItem and it's not in the list.
      while(curPtr != nullptr && curPtr->info < deleteItem) {
         prevPtr = curPtr;
         curPtr = curPtr->link;
      }
      if(curPtr->info != deleteItem) {
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
void orderedLinkedList<Type>::deleteLargest()
{
   orderedLinkedList<Type>::deleteNode(this->last->info);
}

#endif
