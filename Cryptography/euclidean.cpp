/*
   Ryan Hirscher - Euclidean Algorithm to find the GCD of 2 large numbers
   g++ euclidean.cpp
   ./a.out<input.txt
*/

#include<iostream>
#include<math.h>
using namespace std;
int gcd(int,int, int);
int main()
{
   int highest;
   int lowest;
   cout << "Enter the highest number: "; //Input
   cin >> highest;
   cout << "Enter the lowest number: ";
   cin >> lowest;   
   cout << gcd(highest,lowest, 1) << endl;
   return 0;
}
int gcd(int high, int low, int previous) //Recursively find the remainders until 1 or zero and return either 1 or previous remainder
{
   int remainder = high%low;
   if(remainder == 1)
      return remainder;
   else if(remainder == 0)
      return previous;
   else
   {
      previous = remainder;
      return gcd(low, remainder, previous); //Call itself
   }
}
