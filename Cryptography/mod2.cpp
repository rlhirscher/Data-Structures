#include<iostream>
using namespace std;
int main()
{
   int check;
   for (int i=0; i<150; i++)
   {
      if(i%8==4 && i%5==3)
      {
         cout << i << endl;
      }
   }

  return 0;
}
