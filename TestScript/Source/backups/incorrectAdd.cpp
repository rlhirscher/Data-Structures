/* Ryan Hirscher
 * CSC4510 Dr. Oudshoorn
 * Assignment 1
 * Incorrect add in C++
*/

#include<iostream>
#include<cmath>
using namespace std;

/* Flip to positive and add 2 integers together by standard in by known language (c++)
 * Pre: Assume that input is at least 2 integers entered on the same line
 * Post: Standard out the absolute value addition of the numbers
*/
int main()
{
   int num1, num2;
   cout << "Enter 2 integers to be added together" << endl;
   cin >> num1 >> num2;

   // Convert to positive if needed
   num1 = abs(num1);
   num2 = abs(num2);

   cout << num1 << " + " << num2 << " = " << num1+num2 << endl;
   return 0;
}
