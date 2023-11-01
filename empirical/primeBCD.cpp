/*
   Authors: Ryan Hirscher and William Phipps
   course: csc2342 - Shore
   path: /home/students/rhirscher/csc2342/projects/primeBCD.cpp
   Date: 2/21/2022

   In this program prompts the user for input values w, x, y, z then checks the value if it is prime using Sum of Products.

   Compile: g++ primeBCD.cpp -o testProg
   Execution: ./testProg

*/
#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

int main()
{
   //Declaration
   int w, x, y, z, num;
   string ans;

   //Prompt and input (no input validation)
   cout << "w = ";
   cin >> w;
   cout << "x = ";
   cin >> x;
   cout << "y = ";
   cin >> y;
   cout << "z = ";
   cin >> z;

   //Binary -> decimal
   num = (pow(2, 3)*w)+ (pow(2, 2)*x)+(pow(2, 1)*y)+(pow(2, 0)*z); //Adding the weights of binary positions where it is 1

   //Consider output string variable ans to either be (a prime) or (not a prime). Uses Sum of Products
   if ((~x&y|y&z|x&z) == 1)
      ans = " a ";
   else
      ans = " not a ";

   cout << "BCD " << w << x << y << z << " represents digit " << num << " and is" << ans << "prime number." << endl;
   return 0;
}
