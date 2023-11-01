#ifndef LINKED_LIST_TYPE
#define LINKED_LIST_TYPE

#include<iostream>
#include<cassert>
using namespace std;


//************************ list node definition ******************
template <class Type>
struct nodeType
{
   Type info;
   nodeType<Type> * link;
};


//************************ list iterator definition ******************
template <class Type>
class linkedListIterator
{
   private:
      nodeType<Type> *curptr; //pointer to point to the curptr 
                            //node in the linked list
   public:
      linkedListIterator();
      //Default constructor
      //Postcondition: curptr = NULL;

      linkedListIterator(nodeType<Type> *ptr);
      //Constructor with a parameter.
      //Postcondition: curptr = ptr;

      Type operator*();
      //Function to overload the dereferencing operator *.
      //Postcondition: Returns the info contained in the node.
 
      linkedListIterator<Type> operator++();
      //Overload the pre-increment operator.
      //Postcondition: The iterator is advanced to the next 
      //               node.

      bool operator==(const linkedListIterator<Type>& right) const;
      //Overload the equality operator.
      //Postcondition: Returns true if this iterator is equal to 
      //               the iterator specified by right, 
      //               otherwise it returns the value false.
 
      bool operator!=(const linkedListIterator<Type>& right) const;
      //Overload the not equal to operator.
      //Postcondition: Returns true if this iterator is not  
      //               equal to the iterator specified by  
      //               right; otherwise it returns the value 
      //               false.

};

//************************ list iterator implementation ******************
template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
   curptr = nullptr;
}

template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr)
{
   curptr = ptr;
}

template <class Type>
Type linkedListIterator<Type>::operator*()
{
   assert(curptr != nullptr);
   return curptr->info;
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
   assert(curptr != nullptr);
   curptr = curptr->link;
   return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const
{
   return (curptr == right.curptr);
}

template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const
{
   return (curptr != right.curptr);
}

//*********************** linked list base class **********************

template <class Type>
class linkedListType
{
   protected:
      int count;  //number of elements in the list
      nodeType<Type> *first;  //point to first node
      nodeType<Type> *last;   //point to last node

   public:
      void feederPrintF();
      //Function to call recursive function to print info.
      //Precondition: Information is not given to recursive print to print the info
      //Postcondition: Information is sent to the recursive print to print the info

      void feederPrintR();
      //Function to call recursive function to print info.
      //Precondition: Information is not given to recursive print to print the info
      //Postcondition: Information is sent to the recursive print to print the info


      void listKiller();
      //Function to delete and deallocate a linked list.
      //Precondition: The list is there.
      //Postcondition: The list is deleted (killed).

      linkedListType();
      //default constructor
      //Initializes the list to an empty state.
      //Postcondition: first = NULL, last = NULL, count = 0; 

      linkedListType(const linkedListType<Type>& otherList);
      //copy constructor

      ~linkedListType();
      //destructor
      //Deletes all the nodes from the list.
      //Postcondition: The list object is destroyed. 

      Type front() const;
      //Function to return the first element of the list.
      //Precondition: The list must exist and must not be 
      //              empty.
      //Postcondition: If the list is empty, the program
      //               terminates; otherwise, the first 
      //               element of the list is returned.

      Type back() const;
      //Function to return the last element of the list.
      //Precondition: The list must exist and must not be 
      //              empty.
      //Postcondition: If the list is empty, the program
      //               terminates; otherwise, the last  
      //               element of the list is returned.

      bool isEmpty() const;
      //Function to determine whether the list is empty. 
      //Postcondition: Returns true if the list is empty,
      //               otherwise it returns false.

      void print() const;
      //Function to output the data contained in each node.
      //Postcondition: none

      int length() const;
      //Function to return the number of nodes in the list.
      //Postcondition: The value of count is returned.

      const linkedListType<Type>& operator=(const linkedListType<Type>& otherList);
      //overload assignment operator
 
      virtual bool search(const Type& newItem)const = 0;
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the 
      //               list, otherwise the value false is 
      //               returned.
 
      virtual void insertFirst(const Type& newItem) = 0;
      //Function to insert newItem at the beginning of the list.
      //Postcondition: first points to the new list, newItem is
      //               inserted at the beginning of the list,
      //               last points to the last node in the list, 
      //               and count is incremented by 1.
      // NOTE: pure virtual - derived classes must implement this one
 
      virtual void insertLast(const Type& newItem) = 0;
      //Function to insert newItem at the end of the list.
      //Postcondition: first points to the new list, newItem 
      //               is inserted at the end of the list,
      //               last points to the last node in the list,
      //               and count is incremented by 1.
      // NOTE: pure virtual - derived classes must implement this one
 
      virtual void deleteNode(const Type& deleteItem) = 0;
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing 
      //               deleteItem is deleted from the list.
      //               first points to the first node, last
      //               points to the last node of the updated 
      //               list, and count is decremented by 1.
      virtual void deleteLargest() = 0;
      //Function to delete the largest item in the linked list.
      //Postcondition: The largest is found and then that node
      //               is deleted from the linked list.
      //               deleteNode is called to delete that node.
 
      linkedListIterator<Type> begin();
      //Function to return an iterator at the begining of the 
      //linked list.
      //Postcondition: Returns an iterator such that curptr is
      //               set to first.
 
      linkedListIterator<Type> end();
      //Function to return an iterator one element past the 
      //last element of the linked list. 
      //Postcondition: Returns an iterator such that curptr is
      //               set to NULL.
 
   private:
      void forwardPrint(nodeType<Type>*) const;
      //Function to recursively output the data contained in each node (forwards).
      //Postcondition: The information is outputted through cout

      void reversePrint(nodeType<Type>*) const;
      //Function to recursively output the data contained in each node (backwards).
      //Postcondition: The information is outputted through cout

      void copyList(const linkedListType<Type>& otherList);
      //Function to make a copy of otherList.
      //Postcondition: A copy of otherList is created and
      //               assigned to this list.

      //void listKiller();
      //Function to delete and deallocate a linked list.
      //Precondition: The list is there.
      //Postcondition: The list is deleted (killed).
};
//*********************** linked list implementation **********************

template <class Type>
linkedListType<Type>::linkedListType()
{
   first=last=nullptr;
   count=0;
}

template <class Type>
linkedListType<Type>::~linkedListType()
{
   linkedListType<Type>::listKiller();
}

template <class Type>
void linkedListType<Type>::listKiller()
{
   nodeType<Type> *tmp;

   while(first!= nullptr) {
      tmp = first;
      first = first->link;
      delete tmp; 
   }
   last = nullptr;
   count = 0;
}

template <class Type>
Type linkedListType<Type>::front() const
{
   assert(first != nullptr);
   return first->info;
}

template <class Type>
Type linkedListType<Type>::back() const
{
   assert(last != nullptr);
   return last->info;
}

template <class Type>
bool linkedListType<Type>::isEmpty() const
{
   return first==nullptr;
}

template <class Type>
void linkedListType<Type>::print() const
{
   nodeType<Type> *cur=first;
   if (!isEmpty())
   {
      while(cur != nullptr) {
         cout << cur->info << " " << endl;
         cur = cur->link;
      }
   }
   else
      cout << "Empty." << endl;
}

template <class Type>
void linkedListType<Type>::feederPrintF()
{
   nodeType<Type> *ptr; //Making a new pointer
   ptr = first; //Assigning it to first
   if (ptr == nullptr)
      cerr << "Empty.";
   else
      forwardPrint(ptr); //Feeding to recursive forward function
}

template <class Type>
void linkedListType<Type>::feederPrintR()
{
   nodeType<Type> *ptr; //Making a new pointer
   ptr = first; //Assigning it to first
   if (ptr == nullptr)
      cerr << "Empty.";
   else
      reversePrint(ptr); //Feeding to recursive reverse function
}
template <class Type>
void linkedListType<Type>::forwardPrint(nodeType<Type> *ptr) const
{
   if (ptr != nullptr) //Stops when ptr is equal to nullptr
   {
      cout << ptr->info << " " << endl; //Output node info
      forwardPrint(ptr); //Do the next node
   }
   
}

template <class Type>
void linkedListType<Type>::reversePrint(nodeType<Type> *ptr) const
{
   if (ptr->link != nullptr) //Stops when ptr is equal to nullptr
   {
      reversePrint(ptr->link); //Call the recursive function for next node
      cout << ptr->info << " " << endl; //Print the element in that node (recoils here)
   }
}

template <class Type>
int linkedListType<Type>::length() const
{
   return count;
}

template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList)
{
   first = nullptr;
   copyList(otherList);
}

template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& otherList)
{
   if(this != &otherList)
      copyList(otherList);
   return *this;

}

template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList)
{
   if(this->first != nullptr) {
      //target list is not empty - empty it.
      linkedListType<Type>::listKiller();
   }
   if(otherList.first == nullptr) {
      //the source list is empty
      first = last = nullptr;
      count = 0;  
   } else {
      nodeType<Type> *curPtr;
      nodeType<Type> *newNode;
   
      count = otherList.count;
      //point to first node in the other list
      curPtr = otherList.first;
      //setup the new list with the first node
      first = new nodeType<Type>;
      first->info = curPtr->info;
      first->link = nullptr;
     
      //get ready to copy the rest of the list to
      //the new list.  last will track the new list
      //while curPtr will track the other list. 
      last = first;
      curPtr = curPtr->link; 
      while(curPtr != nullptr) {
         newNode = new nodeType<Type>;
         newNode->info = curPtr->info;
         newNode->link = nullptr;
        
         //tie in new node on end of the new list 
         last->link = newNode;
         last = newNode;
        
         //move to the next node in the other list. 
         curPtr = curPtr->link;
      }
   }
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
   linkedListIterator<Type> temp(first);
   return temp;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
   linkedListIterator<Type> temp(nullptr);
   return temp;
}

#endif
