#include <iostream>
#include <math.h>
using namespace std;
int main()
{
   int k;
   int n=8;
   int a=13;
   cin >>k;
   for (int i=0;i<n;i++)
   {
      cout << static_cast<int>(pow(a,k+i))%n << endl;
      cout << " pow: " << k+i << " a: " << a << endl;
   }


   return 0;
}
