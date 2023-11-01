/*
   Ryan Hirscher
   /home/students/rhirscher/csc2710/programs/projectTwo/hirscher_Floyd.cpp
   11/12/2021
   Dr. Williams csc2710 Advanced Data Structures and Algorithms

   This program takes in 2 data files and reads in direct node connections and applies them to a matrix. W matrix is found and proper notation is applied. Then the Traveling Salesman Program is implemented to find the Final Matrix of shortest paths from to each node. The path matrix is made by the matching the proper D matrix iteration where it applies. 

   Compile: g++ hirscher_Floyd.cpp -o testProg
   Execute: ./testProg

*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#define INFINITY 2000;
using namespace std;
void floyds(int b[][7], int n, int p[][7]);
void path(int p[][7], int q, int r);
int find_w(int b[][7], int n, int p[][7]);

int main()
{
   int n = 0;
   ifstream inFile;
   string line;
   string filename;
   int matrix[7][7];
   int p[7][7];
   int m;
   n = find_w(matrix, n, p);
   floyds(matrix, n, p);
   cout << "Enter filename (data2): ";
   cin >> filename;
   inFile.open(filename);
   inFile >> m;
   int position_one;
   int position_two;
   for (int i=0; i<m; i++)
   {
      inFile >> line;
      position_one = line[1];
      inFile >> line;
      position_two = line[1];
      position_one = position_one-48; //Converting properly
      position_two = position_two-48;
      if (matrix[position_one][position_two] < 1999) //if the position is infinity (after final matrix) then it has no (in for row and out for column)connection
      {
         cout << "Path from v" << position_one << " to v" << position_two << " ==> v" << position_one << " ";
         path(p, position_one, position_two);
         cout << "v" << position_two << endl;
      }
      else
         cout << "No path between v" << position_one << " and v" << position_two << endl;
   }
   return 0;
}
/* Function path passes the p matrix, q, and r to find the shortest possible paths
** from a node to another recursively
*/
void path(int p[][7], int q, int r)
{
   if (p[q][r] != 0)
   {
      path(p, q, p[q][r]);
      cout << "v" << p[q][r] << " ";
      path(p, p[q][r], r);
   }
}
/* Function passes the original matrix, the size n, and the p matrix to find the
** initial w matrix. It also reads in the data file which contains the direct
** connection information as well as the number of nodes and edges.
*/
int find_w(int b[][7], int n, int p[][7])
{
   ifstream inFile;
   string filename;
   int m;
   cout << "Enter filename (data1): "; //Open datafile and read in first n and m
   cin >> filename;
   inFile.open(filename);
   inFile >> n;
   n++;
   inFile >> m;
   m++;
   int position_one[m];
   int position_two[m];
   int distance[m];
   string line;
   for (int s=1; s<m;s++) //Read in each edge
   {
      inFile >> line;
      position_one[s] = line[1]; //Second character of row (ex: 1 of v1)
      inFile >> line;
      position_two[s] = line[1]; //Second character of column
      inFile >> distance[s];
   }
   inFile.close();
   for (int i = 1; i < n; i++)
   {
       for (int j = 1; j < n; j++)
       {
          if (j == i)
             b[i][j] = 0; //Set where i and j are equal to 0
          else
             b[i][j] = INFINITY; //Set all to infinity intially
       }
   }
   for (int s=1; s<m; s++) //Apply weight of direct connections
      b[position_one[s]-48][position_two[s]-48] = distance[s]; //For some reason when converting from string[1] it increments by an additional 48

   cout << "w Matrix" << endl; //Output w matrix
   cout << "       v1    v2    v3    v4    v5    v6" << endl;
   for (int i = 1; i < n; i++)
   {
      cout << "v" << i << "   ";
      for (int j = 1; j < n; j++)
      {
        p[i][j] = 0; //Set all positions of p to 0
        if (b[i][j] >= 2000)
           cout << setw(4) << "INF" << "  "; //adjust properly
        else
         cout << setw(4) << b[i][j] << "  "; //adjust properly
      }
      cout << endl;
   }
   return n; //Return size
}
void floyds(int b[][7], int n, int p[][7])
{
   int i = 1; //Start with 1st positions for matrix
   int j = 1;
   int k = 1;
   for (k = 1; k < n; k++)
   {
      for (i = 1; i < n; i++)
      {
         for (j = 1; j < n; j++)
         {
            if ((b[i][k] * b[k][j] != 0) && (i != j))
            {
               if ((b[i][k] + b[k][j] < b[i][j]) || (b[i][j] == 0)) //Checking condition
               {
                  b[i][j] = b[i][k] + b[k][j]; //adjust original matrix
                  p[i][j] = k; //Apply to p matrix
               }
            }
         }
      }
   }
   cout << "p Matrix" << endl; //Output finished p matrix
   cout << "       v1    v2    v3    v4    v5    v6" << endl;
   for (i = 1; i < n; i++)
   {
      cout << "v" << i << "   ";
      for (j = 1; j < n; j++)
      {
         if (p[i][j] == 0 && i != j)
            cout << setw(4) << "N/A" << "  ";
         else
            cout << setw(4) << p[i][j] << "  ";
      }
      cout << endl;
   }
   cout << "Final Matrix" << endl; //Output finished original matrix
   cout << "       v1    v2    v3    v4    v5    v6" << endl;
   for (i = 1; i < n; i++)
   {
      cout << "v" << i << "   ";
      for (j = 1; j < n; j++)
      {
        if (b[i][j] >= 2000)
           cout << setw(4) << "INF" << "  ";
        else
         cout << setw(4) << b[i][j] << "  ";
      }
      cout << endl;
   }
}
