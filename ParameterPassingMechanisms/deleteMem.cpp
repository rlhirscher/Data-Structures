/* Ryan Hirscher
 * Dr. Oudshoorn
 * CSC4510
 * Assignment 2 Deleting pointer
 *
 * Compiler will warn about the deallocation of a pointers memory referencing a variable. 
*/


#include <iostream>
using namespace std;
int main()
{
   int a = 5;
   int alias = a;
   int *ptr = &alias;
   alias++;

   delete ptr;
   cout << "*ptr = " << *ptr << endl;
   a++;
   cout << "*ptr = " << *ptr << endl;
   return 0;
}
