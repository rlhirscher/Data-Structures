/* Ryan Hirscher
 * Dr. Oudshoorn
 * CSC4510
 * Assignment 2 Call by Reference with pointers in C++
 *
 * This program attempts to see if C++ supports call by reference and then examines the mechanism by its values, scope, and memory locations. Similarly to passing & in call by value-result, we are passing a pointer of the actual argument to the formal variable. We should expect very similar results to that of the call by value-result. They are both in-out mechanisms, but here we are examining if pointing to the address will differ from referencing the address with &.
 *
 * The addresses of x and y were passed to the swap function through pointers. The swap was performed within the function using formals. The swap of values retained outside the scope of the function and the addresses of x and y remained the same throughout the test. In C++, pass by reference usually is performed with &, but the same can be implemented with pointers. Here we are passing the actual address of the argument.
*/
void swap(int *, int *);
#include<iostream>
using namespace std;
int main ()
{
   
   int x=10;
   int y=999;
   
   //A will point to the address of x
   //B will point to the address y
   int *A=&x;
   int *B=&y;

   //Print Actual value start
   cout << "Pass by reference to swap function" << endl;
   cout << "Pre-swap actual X: " << *A << endl;
   cout << "X memory address: " << A << endl;
   cout << "Pre-swap actual Y: " << *B << endl;
   cout << "Y memory address: " << B << endl << endl;
   
   //Passing the actuals' address in memory
   swap(A, B);

   //Did the memory location of the actual values change? - They did not change memory locations
   //Did the values change from the function? - The values were successfully swapped 
   cout << "Post-swap actual X: " << *A << endl;
   cout << "X memory address: " << A << endl;
   cout << "Post-swap actual Y: " << *B << endl;
   cout << "Y memory address: " << B << endl << endl;
   
   return 0;
}

void swap (int *x, int *y)
{
   //Swap the formal parameters, Test: Does the swap retain outside of the function scope?
   int temp = *x;
   *x = *y;
   *y = temp;

   //Did the values swap? - The values swapped, the memory locations stayed the same
   cout << "In-swap formal X: " << *x << endl;
   cout << "X memory address: " << x << endl;
   cout << "In-swap formal Y: " << *y << endl;
   cout << "Y memory address: " << y << endl << endl;

   return;
}

