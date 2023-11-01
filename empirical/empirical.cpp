/* -- Ryan Hirscher and William Phipps --
 *    4/13/2022
 *    CSC 2342 
 *    path: /home/students/rhirscher/csc2342/projects/empirical.cpp
 *    Compile: g++ empirical.cpp -o testProg
 *    Execute: ./testProg
 *
 *    This program empirically compares 3 sorting algorithms to demonstrate
 *    its complexities. The program will determine the number of comparisons, 
 *    element swaps, and time to complete each sort. Each algorithm will
 *    be performed with 5 times with different n values which include:
 *    10,000, 30,000, 50,000, 70,000, and 90,000 elements. The user will
 *    choose the input file, n, the algorithm number, and if they want
 *    to see the output of the sorted array.
*/

#include <iostream>
#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
long int c_cnt=0;
long int m_cnt=0;
void bubbleSortOne(string arr[], long int n); //Bubble version one
void bubbleSortTwo(string arr[], long int n); //Bubble version two
void insertionSort(string arr[], long int n); //Insertion sort
void Print(string arr[], long int n); //Print function
void load(string arr[], string filename, long int n); //Load function
int main()
{
   string filename;
   string arr[100000];
   string alg;
   long int n=0;
   int choice=0;
   double diff, start, stop;
   struct timeval startTime, stopTime;
   string see;
   system("clear");
   cout << "Please enter the filename(words.txt): ";
   cin >> filename; //Prompt for filename
   do 
   {
      system("clear");
      cout << "10 <= n <= 98913" << endl;
      cout << "Please enter n: ";
      cin >> n;
   } while(n < 10 || n > 98913); //Validation for n size

   load(arr, filename, n); //Load up the array and check file
   do
   {
      system("clear");
      cout << "Choose an algorithm." << endl;
      cout << "[1] Bubble sort version 1 with " << n << " elements." << endl;
      cout << "[2] Bubble sort version 2 with " << n << " elements." << endl;
      cout << "[3] Insertion sort with " << n << " elements." << endl;
      cout << "Enter the corresponding number: ";
      cin >> choice;
   } while(choice != 1 && choice != 2 && choice != 3); //Validation for options

   gettimeofday(&startTime,NULL); //Get start time
   switch(choice) //Given the option execute one of the functions
   {
      case 1:
         bubbleSortOne(arr, n);
         alg = "Bubble sort version 1 with " + to_string(n) + " elements.";
         break;
      case 2:
         bubbleSortTwo(arr, n);
         alg = "Bubble sort version 2 with " + to_string(n) + " elements.";
         break;
      case 3:
         insertionSort(arr, n);
         alg = "Insertion sort with " + to_string(n) + " elements.";
         break;
   }
   gettimeofday(&stopTime,NULL); //Get end time
   start = startTime.tv_sec+(startTime.tv_usec/1000000.0);
   stop = stopTime.tv_sec+(stopTime.tv_usec/1000000.0);
   diff = stop-start; //Convert time and find difference
   do
   {
      system("clear");
      cout << alg << endl;
      cout << "Comparison count: " << c_cnt << " comparisons." << endl;
      cout << "Element movement count: " << m_cnt << " movements." << endl;
      cout << "Time: " << fixed << setprecision(10) << diff << " seconds" << endl;
      cout << "See the sorted array? (Y/N): ";
      cin >> see;
   } while(see != "Y" && see != "y" && see != "N" && see != "n"); //Print results and validation for Y/N to see string results
   if (see == "Y" || see == "y")
      Print(arr, n);
   return 0;
}
//Function definitions

/* Function load passes an array of strings, filename, and the size.
 *               Using ifstream a file is opened and each element is
 *               read into the array. The file is then closed
 * Pre-condition: Array not loaded.
 * Post-condition: Array is loaded.
 */
void load(string arr[], string filename, long int n)
{
   ifstream inFile;
   inFile.open(filename);
   if(!inFile)
   {
      cerr << "File does not exist." << endl;
      exit(1);
   }
   for (int i=0; i<n; i++)
   {
      inFile >> arr[i];
   }
   inFile.close();
}

/* Function bubbleSortOne passes an arry of strings and the size.
 *                        This function sorts the give array and
 *                        has a time complexity of O(n^2). C=1.
 * Pre-condition: Array is in loaded order.
 * Post-condition: Array is sorted.
*/
void bubbleSortOne(string arr[], long int n)
{
   string temp;
   for (int i=0; i<n-1; i++)
   {
      for (int j=0; j<n-1; j++)
      {
         c_cnt++;
         if (arr[j] > arr[j+1])
         {
            m_cnt+=3;
            temp = arr[j]; //Swap
            arr[j] = arr[j+1];
            arr[j+1] = temp;
         }
      }
   }

}

/* Function bubbleSortTwo passes an array of strings and the size.
 *                        This function sorts the given array and
 *                        has a time complexity of O(n^2). C=0.5.
 * Pre-condition: Array is in loaded order.
 * Post-condition: Array is sorted.
*/
void bubbleSortTwo(string arr[], long int n)
{
   string temp;
   for (int i=1; i<n; i++)
   {
      for (int j=0; j<n-i; j++)
      {
         c_cnt++;
         if (arr[j] > arr[j+1])
         {
            m_cnt+=3;
            temp = arr[j]; //Swap
            arr[j] = arr[j+1];
            arr[j+1] = temp;            
         }
      }
   } 
}

/* Function insertionSort passes an array of strings and the size.
 *                        This function sorts the given array and
 *                        has a time complexity of O(n^2). C=0.25.
 * Pre-condition: Array is in loaded order.
 * Post-condition: Array is sorted.
 *
*/
void insertionSort(string arr[], long int n)
{
   int i=0;
   string m;
   for (int j=1; j<n; j++)
   {
      i=0;
      while (arr[j] > arr[i])
      {
         c_cnt++; //For every While condition that is true
         i = i+1;
      }
      c_cnt++; //When it is false
      m= arr[j];
      for (int k=0; k<j-i+1; k++)
      {
         arr[j-k] = arr[j-k-1];
         m_cnt++; //Move every iteration
      }
      arr[i] = m;
      m_cnt++; //Move 
   }
}

/* Function Print passes an array of strings and the size.
 *                This function prints all elements of the
 *                array and separates each element with a
 *                comma.
 * Pre-condition: The array is filled.
 * Post-condition: The array is printed to standard out.
*/
void Print(string arr[], long int n)
{
   for (int i=0; i<n; i++)
   {
      if (i == n-1)
         cout << arr[i] << endl;
      else
         cout << arr[i] << ", ";
   }
}
