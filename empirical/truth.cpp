/*
   Ryan Hirscher
   csc2342
   /home/students/rhirscher/csc2342/projects/truth.cpp
   1/31/2022

   This program defines 3 inputs (a, b, c) and outputs all combinations as a truth table from 0-7 from decimal to binary. The program itself converts decimal to binary getting the decimal from its for loop. Zero placeholders above its value are filled. Then 2 final columns F(a, b, c) and G(a, b, c) are defined as Fout and Gout where F is equal b&(~a|c) and G is equal to a&b&c|~a&b&c|~a&b&~c.

   Compile: g++ truth.cpp
   Execute: ./a.out
*/

#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
   //Inputs a, b, and c
   bool a = 0;
   bool b = 0;
   bool c = 0;
   bool Fout;
   bool Gout;
   int n =0;
   int convert; //For converting string binary to integer to then convert to bool for function
   string r; //Converting to binary. Temporary string buffer to build binary
   string bin[3]; //Output for binary. This holds 3 positions for binary [0], [1], [2] for suitable output
   int x=0; //For the index of bin
   cout << "a b c F G " << endl;
   cout << "---------" << endl;
   for (int i=7; i>=0; i--) //Count down
   {
      n=i;//Cannot use i since there are changes, thus use n
      while(n!=0) //Builds binary number from n 
      {   
         r=(n%2==0 ?"0":"1"); //Build one placeholder
         bin[x++] = r; //Set to bin position
         r+=r; //Carry
         n/=2; //Next
      }

      //This fixes empty placeholders to correct to zeros
      if (bin[2] != "1" && bin[2] != "0")
         bin[2] = "0";
      if (bin[1] != "1" && bin[1] != "0")
         bin[1] = "0";
      if (bin[0] != "1" && bin[0] != "0")
         bin[0] = "0";

      convert = stoi(bin[2]); //Converting string to int -> binary
      a=convert; //Stored into a
      convert = stoi(bin[1]);
      b=convert; //Stored into b
      convert = stoi(bin[0]);
      c=convert; //Stored into c

      Fout = b&(~a|c); //F function of a, b, c in this instance
      Gout = a&b&c|~a&b&c|~a&b&~c; //G function of a, b, c in this instance

      //Each row output
      cout << a << " " << b << " " << c << " " << Fout << " " << Gout << endl;

      x=0; //Reset x for bin
      bin[0]=bin[1]=bin[2]="0"; //Reset bin
   }
   cout << "---------" << endl;

   return 0;
}
