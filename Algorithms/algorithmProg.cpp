/*
   Ryan Hirscher
   CSC1720
   /home/students/rhirscher/csc2710/programs/algorithmProg.cpp
   9/10/2021
   A Level

   This program demonstrates Sequential search, Exchange sort, Binary search, and the Fibonacci sequence done iteratively and recursively. Both searches have a 100 term array, counter, and a user prompt for an input value. The exchange sort displays before and after values of a 100 term array. The revurisve Fibonacci sequence counts each time a term was added in the tree while the iterative counts the terms that were added together up to a specified term.

*/
#include <iomanip>
#include <iostream>
using namespace std;
/*Function fillArray is used to fill an array of 100 terms with random numbers
   Precondition: Array not filled.
   Postcondition: Array is filled with random numbers ranging from 0 to 100.
*/
void fillArray(int myArray[], int arraySize);

/*Function seqSearch passes an array, the search item, the size, and a count by reference. It will check each item in the array for the search item and return the position in the array.
   Precondition: The item in the array is not found.
   Postcondition: The function ended to return the item or exceeded the size and returned -1.
*/
int seqSearch(int myArray[], int item, int arraySize, int &count);

/*Function exchangeSort passes an array, the size, and the count by reference. It will go through the array exchanging numbers by difference until ascending order. It returns nothing.
   Precondition: The list is not ordered.
   Postcondition: The list is ordered.
*/
void exchangeSort(int myArray[], int arraySize, int &count);

/*Function binarySearch passes the array, the size, the search item, and the count by reference. It accounts for an ordered array and divides and conqures to reach the search item faster and in less iterations.
   Precondition: The list is ordered and the item is not found.
   Postcondition: The item is found and the position is returned or it is not in the list and it exceeds iteration.
*/
int binarySearch(int myArray[], int arraySize, int num, int &count);

/*Function fibonacciIt passes the term to find up to and the count by reference. It lists each item of the sequence up to a specified term including the first 0 number by iteration. It counts the number of times numbers were added together up to the term.
   Precondition: The sequence is not outputted.
   Postcondition: The sequence is printed up to a term.
*/
void fibonacciIt(int num, int &count);

/*Function fibonacciRec passes the term to find and count by reference. It returns the following number in the sequence and calls itself recursively to find the term specified.
   Precondition: The term is not found.
   Postcondition: The term is found and returned.
*/
int fibonacciRec(int num, int &count);
int main()
{
    int array1[100];
    int num;
    int count =0;
    int result;
    fillArray(array1, 100);
///////////////////////////////////////// SEQ SEARCH /////////////////////////////////////////////
    cout << endl << "------------Sequential Search------------" << endl;
    cout << "Enter the first number to search for in the array: ";
    cin >> num;
    result = seqSearch(array1, num, 100, count);
    if (result == -1)
        cout << num << " was not found in the array." << endl;
    else
        cout << num << " was first found at position " << result << " and compared " << count << " times." << endl;
    count = 0;
/////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////// EXCHANGE SORT /////////////////////////////////////////
    cout << endl << "------------Exchange Sort of array------------" << endl;
    for (int x=0; x<100; x++)
       cout << array1[x] << " ";
    cout << endl;
    exchangeSort(array1, 100, count);
    cout << "The array was sorted with " << count << " passes." << endl;
    for (int x=0; x<100; x++)
       cout << array1[x] << " ";
    cout << endl;
    count = 0;
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////// BINARY SEARCH ///////////////////////////////////////
    cout << endl << "------------Binary Search of array------------" << endl;
    cout << "Enter a search item: ";
    cin >> num;
    result = binarySearch(array1, 100, num, count);
    if (result == -1)
        cout << num << " was not found in the array." << endl;
    else
        cout << num << " was found at position " << result << " and compared " << count << " times." << endl;
    count = 0;
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////// FIBONACCI RECURSIVE /////////////////////////////////
    cout << endl << "------------Fibonacci Recursive------------" << endl; 
    cout << "Enter the term for the sequence: ";
    cin >> num;
    result = fibonacciRec(num, count);
    cout << "The " << num << " term is " << result << " and added " << count << " terms in the tree. (OMITING 0 FIRST TERM)" << endl;
    count = 0;
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////// FIBONACCI ITERATIVE /////////////////////////////////
    cout << endl << "------------Fibonacci Iterative------------" << endl;
    cout << "Enter the term to find up to in the sequence: ";
    cin >> num;
    fibonacciIt(num, count);
    if (count != -1)
       cout << endl << "Terms were added " << count << " times." << endl;
    else
       cout << endl << "No terms were added." << endl;
    count = 0;
/////////////////////////////////////////////////////////////////////////////////////////////////
    return 0;
}
int fibonacciRec(int num, int &count)
{
   if (num == 0) //First terms
      return 0;
   if (num == 1)
      return 1;
   else
   {
      count++; //Add everytime a number is added
      return (fibonacciRec(num-1, count) + fibonacciRec(num-2, count));
   }
}
void fibonacciIt(int num, int &count)
{
   int x = 0;
   int y = 1;
   int next = 0;
   for (int i=0; i<num; i++)
   {
      cout << x <<  " ";
      next = x + y; //Get the next term
      x = y;
      y = next; //Continue
      count++;
   }
   count--; //0
}
int binarySearch(int myArray[], int arraySize, int item, int &count)
{
   int left = 0;
   int right = arraySize-1; //n-1
   int mid;
   bool found = false;
   if (myArray[left] > item || myArray[right] < item)
      return -1;
   while (left <= right && !found)
   {
      mid = (left + right)/2; //Gets mid. 
      count++;
      if (item == myArray[mid])
         found = true;
      else if (item > myArray[mid])
         left = mid+1;
      else
         right = mid-left;
   }
   if (found == false)
      return -1; //Not found
   else
      return mid;
}
void exchangeSort(int myArray[], int arraySize, int &count)
{
   int temp;
   for (int x=0; x<arraySize-1; x++)
   {
      count++;
      for (int j=0; j<arraySize-1; j++)
      {
         if (myArray[j] > myArray[j+1])
         {
            temp = myArray[j];
            myArray[j] = myArray[j+1];
            myArray[j+1] = temp;
         }
      }
   }  

}
int seqSearch(int myArray[], int item, int arraySize, int &count)
{
   for (int x = 0; x<arraySize; x++)
   {
      count++;
      if (myArray[x] == item)
         return x;
   }
      return -1;
}
void fillArray(int myArray[], int arraySize)
{
    srand(time(0));
    for (int i = 0; i < arraySize; i++)
    {
        int numRand = rand() % 101; //Include 100
        myArray[i] = numRand;
    }
}

