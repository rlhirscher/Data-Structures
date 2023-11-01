/* Ryan Hirscher 
 * CSC4510
 * Dr. Oudshoorn
 * Assignment 3 Template Sort in C++
 *
 * This program templates a simple bubble sort and is able to sort chars based on the ASCII value, integers, and floats.
*/

#include<iostream>
#include<cstring>
#include<string>
using namespace std;
template <typename T>
void bubble_sort(T a[], int n);

int main()
{
   int n=0;
   int in_type;
   string array[20];
   int arr[20];
   float ar[20];

   //First input in the file is the type of data for that test case
   cin >> in_type;
   if (in_type != 1 && in_type != 2 && in_type != 3)
   {
      cerr << "Bad input. It must begin with the data type for input." << endl;
      cerr << "Options: float, int, and char." << endl;
      exit(1);
   }

   //Get the size of the input and store into string array
   while (cin >> array[n])
      n++;

   //Unsorted
   cout << "Unsorted array:" << endl;
   for (int i=0; i<n; i++)
      cout << array[i] << " ";
   cout << endl << endl << "Sorted:" << endl;

   //Based on the input, copy string array to corresponding input type array and pass to to sort
   //Print new sorted array
   //Does not support dynamic allocation of arrays inside switch cases.
   switch (in_type) 
   {
      case 1:
         for (int i=0; i<n; i++)
            arr[i] = stoi(array[i]);
         bubble_sort<int>(arr, n);
         for (int i=0; i<n; i++)
            cout << arr[i] << " ";
         cout << endl;
         break;
      case 2:
         for (int i=0; i<n; i++)
            ar[i] = stof(array[i]);
         bubble_sort<float>(ar, n);
         for (int i=0; i<n; i++)
            cout << ar[i] << " ";
         cout << endl;
         break;
      case 3:
         bubble_sort<string>(array, n);
         for (int i=0; i<n; i++)
            cout << array[i] << " ";
         cout << endl;
         break;
      default:
         cerr << "Invalid input type. Error." << endl;
         break;
   }
}

// Bubble sort orders the array in ascending value, arrays are always passed by reference
// PRE: Unsorted array of type char, int, or float
// POST: Array is sorted ascending
template <typename T> 
void bubble_sort( T a[], int n )
{
   int i,j;
   T temp ;
   for(i=0; i<n; i++)
   {
      for(j=i+1; j<n; j++)
      {
         if(a[i]>a[j])
         {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
         }
      }
   }
}
