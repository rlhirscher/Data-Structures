/* Ryan Hirscher
 * Dr. Oudshoorn
 * CSC4510
 * Assignment 2 Pass by Value C++
 *
 * This program attempts to demonstrate C++ pass by value mechanism and scope with a swap function and printing out the values and addresses of the actual and formal variables.
 *
 * The Pass by value was a success, C++ supports pass by value. Actual variables passed on values to formal variables without sharing or retaining memory address and actual variables were not updated by function return.
*/

#include<iostream>
using namespace std;
void swap (int, int);
int main()
{
   int x=10;
   int y=999;

   //What is the address of the actual values? - Different from the function
   cout << "Pass by value to swap function" << endl;
   cout << "Pre-swap actual X: " << x << endl;
   cout << "X memory address: " << &x << endl;
   cout << "Pre-swap actual Y: " << y << endl;
   cout << "Y memory address: " << &y << endl << endl;
   
   //Passing the actual
   swap(x, y);

   //Did the memory location of the actual values change? - They did
   //Did the values change from the function? - They did not, actuals unchanged
   cout << "Post-swap actual X: " << x << endl;
   cout << "X memory address: " << &x << endl;
   cout << "Post-swap actual Y: " << y << endl;
   cout << "Y memory address: " << &y << endl << endl;
   
   return 0;
}

void swap (int x, int y)
{
   int temp=0;
   temp = x;
   x = y;
   y = temp;

   //Do x and y retain the same memory locations? - They had different locations
   //Did the values swap? - They did in local scope
   cout << "In-swap formal X: " << x << endl;
   cout << "X memory address: " << &x << endl;
   cout << "In-swap formal Y: " << y << endl;
   cout << "Y memory address: " << &y << endl << endl;

   return;
}
