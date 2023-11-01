/*
   Ryan Hirscher - This program takes a base and computes a with a power at a large scale with a modulus. It takes the runtime and outputs.

   Successive Squaring Algorithm - Modular Exponentiation

   g++ expo.cpp
   ./a.out<input.txt
*/

#include<iostream>
#include<math.h> //Power function
#include <chrono> //For runtime Capture
using namespace std;
using namespace std::chrono;

//Structure of elements where there exists a number (base) and a power (exponent)
struct ele{
   long long int po;
   long long int nu;
};
int main()
{
   ele arr[100];
   string bit="";
   long long int num;
   long long int power; 
   int mod;
   cout << "Enter Number:"; //Input
   cin >> num;
   cout << "Enter Power:";
   cin >> power;
   cout << "Enter Modulus:";
   cin >> mod;
   cout << endl;

   int p=0; //power position
   int n=0; //number position
   
   int l=0;
   bool first=true;

   auto start = high_resolution_clock::now(); //Start clock

   for (int i=0; i<100; i++) //Fill with dumby -1
   {
      arr[i].po=-1;
      arr[i].nu=-1;
   }
   int i=1;
   int g=0;
   while (i<power) //For all the powers existing that may fill
   {
      if (first)
      {
         first=false;
         num=static_cast<long long int>(pow(num,1))%mod; //Compute power with 1 for first entry
      }
      else
         num=static_cast<long long int>(pow(num,2))%mod; //Successive squaring compute each value
      arr[g].po=i; //Populate structure array
      arr[g++].nu=num;
      i+=i;
   }
   int count=0;
   bool save=0;
   int w=0;
   long long int total=1;

   //traverse backwards adding the powers together to find binary value
   for (int x=g-1; x>-1; x--)
   {
      if (count<power && arr[x].po != -1)
      {
         count+=arr[x].po;
         save=true;
         if(count>power)
         {
            save=false;
            count-=arr[x].po;
         }
         if (save)
         {
            bit+="1"; //Can add value
            total=(total*arr[x].nu)%mod; //Add to total and modulus
         }
         else
            bit+="0"; //Cannot add value 
      }

   }
   cout << endl << "Bit Final: " << bit << endl; //Output
   cout << "Answer: " << total%mod << endl;
   auto stop = high_resolution_clock::now(); //Stop clock
   auto duration = duration_cast<microseconds>(stop - start); //Difference
   cout << "Runtime in microseconds: " << duration.count() << endl;
   
   return 0;
}
