/*
   Ryan Hirscher
   Cryptography 3010
   Simple Data Encryption Standard
   3/16/2023

   This Program is a model version of DES encryption algorithm.
*/
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

string xor_s (string a, string b);
string sbox (int n, int row, int column);
string expand (string in);
string update_key(string key, int i);
string fun (string R, string K);
string split (int state, string in);
int is_valid(int state, string in);
void compute (int round, int count, string left, string right, string key);

int main()
{
   /* Defaults */
   string zero= "101101101110";
   string key = "011101101";
   string pass = "";
   int MAX=3;

   /* Validate input */
   do {
      cout << "Enter 12 bit string (plaintext) or 'def' to use default: ";
      cin >> pass;
   }while (is_valid(0, pass));

   if (pass != "def")
      zero = pass;

   /* Validate input */
   do {
      cout << "Enter 9 bit string (key) or 'def' to use default: ";
      cin >> pass;
   }while (is_valid(1, pass));
   
   if (pass != "def")
      key = pass;

   cout << "Enter number of rounds: ";
   cin >> MAX;
   
   string left = split(0, zero);
   string right = split(1, zero);
   compute(MAX, 0, left, right, key);
   return 0;
}

int is_valid(int state, string in)
{
   if (in == "def")
      return 0;
   else if (state == 0 && in.length() == 12)
   {
      for (int i=0; i<in.length(); i++)
      {
         if(in[i] != '1' && in[i] != '0')
            return 1; //Return true if invalid to do while
      }
      return 0; //Return false which indicates valid
   }
   else if (state == 1 && in.length() == 9)
   {
      for (int i=0; i<in.length(); i++)
      {
         if(in[i] != '1' && in[i] != '0')
            return 1; //Return true if invalid to do while
      }
      return 0; //Return false which indicates valid
   }
   else
      return 1; //indicating invalid
}

// This function is the drive of the program
// Until the second parameter is equal to or exceeding the first END
// Finds the new Right by previous Left XOR of f(old Right, new Key)
void compute(int MAX, int count, string left, string right, string key)
{
   if (MAX <= count)
   {
      cout << "After " << count << " rounds: " << left+right << endl;
      exit(1);
   }
   else
   {
      /* Set new Left */
      string Ln = right;

      /* Set new right */
      right = xor_s(left, fun(right, update_key(key,count)));

      /* One round complete, pass new L/R */
      count++; 
      compute(MAX, count, Ln, right, key);
   }
}

// This function updates the key at every iteration
// It passes the original key and position to load new key
string update_key(string key, int i)
{
   
   string ans="";
   /* for 0 to the max number of keys-1 copy to wrap around*/
   for (int x=0; x<key.length()-1; x++)
      ans+=key[(x+i)%key.length()];
   return ans;
}

// This function 'fun' performs the f() function in sDES
// It passes the right half and updated key
string fun (string R, string K)
{
   /* pre S box XOR of expanded R and updated key */
   string prebox = xor_s(expand(R), K);

   /* Split to left and right for pre S box */
   string LEFT = split(0, prebox);
   string RIGHT = split(1, prebox);
   string postbox="";
   int row, col;

   /* Convert binary string to integer */
   row = stoi(split(2, LEFT), nullptr, 2);
   col = stoi(split(3, LEFT), nullptr, 2);

   /* Call S box */
   LEFT = sbox(0, row, col);

   /* Convert binary string to integer */
   row = stoi(split(2, RIGHT), nullptr, 2);
   col = stoi(split(3, RIGHT), nullptr, 2);

   /* Call S box */
   RIGHT = sbox(1, row, col);

   /* Combine and return */
   postbox+=LEFT;
   postbox+=RIGHT;   
   return postbox;
}

// This function contains the sboxes and returns row/col matrix
string sbox(int n, int row, int col)
{
   string s1[2][8] = {{"101", "010", "001", "110", "011", "100", "111", "000"},{"001", "100", "110", "010", "000", "111", "101", "011"}};
   string s2[2][8] = {{"100", "000", "110", "101", "111", "001", "011", "010"},{"101", "011", "000", "111", "110", "010", "001", "100"}};

   if (n == 0)
      return s1[row][col];
   else
      return s2[row][col];
}

// This function takes in a bit string and splits in half
// The first parameter determines to return left or right of the bit string
// The second parameter is the full bit string
string split (int state, string in)
{
   string ans="";
   if (state == 0) // Return left
   {
      for (int i=0; i< in.length()/2; i++)
         ans+=in[i];
   }
   else if (state == 1)// Return right
   {
      for (int i=in.length()/2; i<in.length(); i++)
         ans+=in[i];
   }
   else if (state == 2) // Returning first (row) for sboxes
   {
      ans+=in[0];
   }
   else if(state == 3) // Returning last 3 (col) for sboxes
   {
      ans+=in[1];
      ans+=in[2];
      ans+=in[3];
   }
   return ans; 
}

// This funcion passes in a 6 bit string and expands to an 8
string expand (string in)
{
   string ans = "";

   /* Keep the first two */
   ans+=in[0];
   ans+=in[1];

   /* If both middle bits are 1, expand 1s */
   if (in[2] == '1' && in[3] == '1')
   {
      for (int i=0; i<4;i++)
         ans+=in[2]; 
   }

   /* If middle bits 01, flip and alternate */
   else if (in[2] == '0' && in[3] == '1')
   {
      for (int i=0; i<4;i++)
         ans+=(i%2==0) ? in[3] : in[2];
   }

   /* If middle bits 10, flip and alternate */
   else if (in[2] == '1' && in[3] == '0')
   {
      for (int i=0; i<4;i++)
         ans+=(i%2==0) ? in[3] : in[2];
   }

   /* Default/00 */
   else
   {
      for (int i=0; i<4;i++)
         ans+=in[2]; 
   }

   /* Keep the last 2 */
   ans+=in[4];
   ans+=in[5];
   return ans;
}

// This function performs a XOR between 2 bit strings
string xor_s (string a, string b)
{
   string ans = "";
   if (a.length() != b.length())
   {
      cout << "XOR bit length error. Exit." << endl;
      exit(2);
   }
   for (int i = 0; i < a.length(); i++)
   {
      /* If the bit matches */
      if (a[i] == b[i])
         ans += "0";
      else
         ans += "1";
   }
   return ans;
}

