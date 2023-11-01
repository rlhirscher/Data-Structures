/* Ryan Hirscher
 * Dr. Oudshoorn
 * CSC4510
 * Assignment 2 Call by Name C++
 *
 * This program attempts to demonstrate C++ pass by Name mechanism and scope with a swap function and printing out the values and addresses of the actual and formal variables. C++'s "Pass by Reference" uses & to pass the address of a variable in memory. By default by passing a variable this way, the variable name can be changed or aliased in the function header. For example, the actual parameter in the call is x and y, but in the function the formal parameters are 'a' and 'b'. However, they reference the same memory addresses respectively.
 *
 * Additionally however, this is not true for Pass by value, this is only true when you pass with &. Call by Name, is not supported by C++, but similar features can be implemented when done a different way.
 *
 * The formal parameters supports aliasing. When named differently, they still retain the memory address of x and y by passing through &. And the values are copied back to the actual variables.
*/

#include<iostream>
using namespace std;
void swap (int &, int &);
int main()
{
   int x=10;
   int y=999;

   //What is the address of the actual values? - Same as the formals
   cout << "Call by Name to swap function" << endl;
   cout << "Pre-swap actual X: " << x << endl;
   cout << "X memory address: " << &x << endl;
   cout << "Pre-swap actual Y: " << y << endl;
   cout << "Y memory address: " << &y << endl << endl;
   
   //Passing the actual
   swap(x, y);

   //Did the memory location of the actual values change? - They did not change memory locations
   //Did the values change from the function? - They swapped
   cout << "Post-swap actual X: " << x << endl;
   cout << "X memory address: " << &x << endl;
   cout << "Post-swap actual Y: " << y << endl;
   cout << "Y memory address: " << &y << endl << endl;
   
   return 0;
}
// Aliasing a and b to represent the actual parameters x and y respectively
void swap (int &a, int &b)
{
   int temp=0;
   temp = a;
   a = b;
   b = temp;
  
   //Do a (x) and b (y) retain the same memory locations? - They have the same memory locations
   //Did the values swap? - They swapped the values in memory
   cout << "In-swap formal A (X): " << a << endl;
   cout << "A (X) memory address: " << &a << endl;
   cout << "In-swap formal B (Y): " << b << endl;
   cout << "B (Y) memory address: " << &b << endl << endl;

   return;
}
