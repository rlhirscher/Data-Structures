/* Ryan Hirscher
 * Dr. Oudshoorn
 * CSC4510
 * Assignment 2 Call By Result C++
 *
 * This program attempts to demonstrate C++ pass by result  mechanism and scope with a swap function and printing out the values and addresses of the actual and formal variables.
 *
 * C++ does not support out exclusive semantics for parameters, only pass by reference and pass by value. It does not make sense for implementation as it is not a supported feature. However, the feature can be mimiced by passing with & or * with a dummy variable. Since we are referencing the memory, z can be returned while passing in just an empty dummy pointer or address reference.
 * 
*/

#include<iostream>
using namespace std;
void swap (int, int, int&);
int main()
{
   int x=10;
   int y=999;
   int z;
   //What is the address of the actual values? - z is the same as formal, x and y are not the same
   cout << "Call by result to swap function" << endl;
   cout << "Pre-swap actual X: " << x << endl;
   cout << "X memory address: " << &x << endl;
   cout << "Pre-swap actual Y: " << y << endl;
   cout << "Y memory address: " << &y << endl << endl;
   
   //Passing the actual
   swap(x, y, z);

   //Did the memory location of the actual values change? - x and y changed, z did not
   //Did the values change from the function? - The swap did not retain, z actual and formal retained
   cout << "Post-swap actual X: " << x << endl;
   cout << "X memory address: " << &x << endl;
   cout << "Post-swap actual Y: " << y << endl;
   cout << "Y memory address: " << &y << endl;
   cout << "Post-swap actual Z: " << z << endl;
   cout << "Z memory address: " << &z << endl << endl;
   
   return 0;
}

void swap (int x, int y, int &z)
{
   int temp=0;
   temp = x;
   x = y;
   y = temp;
   
   z = x + y;
   //Do x and y retain the same memory locations? - z had the same location, but x and y changed
   //Did the values swap? - They did in local scope
   cout << "In-swap formal X: " << x << endl;
   cout << "X memory address: " << &x << endl;
   cout << "In-swap formal Y: " << y << endl;
   cout << "Y memory address: " << &y << endl;
   cout << "In-swap formal Z: " << z << endl;
   cout << "Z memory address: " << &z << endl << endl;

   return;
}
