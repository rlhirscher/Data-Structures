/* Ryan Hirscher
 * Dr. Oudshoorn
 * CSC4510
 * Assignment 2 Call by Value-result C++
 *
 * This program attempts to demonstrate C++ pass by value-result mechanism by examining the scope and memory locations. It is important to note that C++ does not support value-result, but we can mimic its feature with its native Pass by Reference mechanism.
 *
 * Actual and formal variables shared the same address and values were swapped. The swap retained outside of the function.
*/

#include<iostream>
using namespace std;
void swap (int &, int &);
int main()
{
   int x=10;
   int y=999;

   //What is the address of the actual values? - Same memory locations in the function
   cout << "Call by Value-Result to swap function" << endl;
   cout << "Pre-swap actual X: " << x << endl;
   cout << "X memory address: " << &x << endl;
   cout << "Pre-swap actual Y: " << y << endl;
   cout << "Y memory address: " << &y << endl << endl;
   
   //Passing the actual
   swap(x, y);

   //Did the memory location of the actual values change? - They did not change memory locations
   //Did the values change from the function? - They swapped outside of the scope as well
   cout << "Post-swap actual X: " << x << endl;
   cout << "X memory address: " << &x << endl;
   cout << "Post-swap actual Y: " << y << endl;
   cout << "Y memory address: " << &y << endl << endl;
   
   return 0;
}

void swap (int &x, int &y)
{
   int temp=0;
   temp = x;
   x = y;
   y = temp;

   //Do x and y retain the same memory locations? - They had the same memory locations
   //Did the values swap? - They swapped locally and retained the swap outside the function
   cout << "In-swap formal X: " << x << endl;
   cout << "X memory address: " << &x << endl;
   cout << "In-swap formal Y: " << y << endl;
   cout << "Y memory address: " << &y << endl << endl;

   return;
}
