/*
   Ryan Hirscher
   csc1720
   3/21/2021
   /home/students/rhirscher/csc1720/prog3/listMain.cpp

   This file is the main.cpp file which utilizes the class arrayListType which is the base class that has multiple derived classes: unorderedArrayListType and uniqueListType. Using fstream it loads a list of words into multiple object arrays of the repeating first and last names, a unique one, a repeating first and last, and a non-repeating first and last. The program selects winners for 4 prizes and a grand prize in which a person cannot win more than one prize. The gain from ticket sales is then subtracted by the cost of the event which leaves the profit. This program was fun, I think you will enjoy reading my program or maybe not...

   Compile: g++ -Wall listMain.cpp -o testProg
   Execute: ./testProg
*/
#include <iostream>
#include <string>
#include <iomanip>
#include "arrayListType.h"
#include "unorderedArrayListType.h" 
#include "uniqueListType.h"
#include <fstream>
#include <cstdlib>
using namespace std;

/* load: function loads strings through inFile into objects passed by reference into the lists of those objects. The lists will only load if the lists are not full and the file is not at the end.
   precondition: Names are not loaded into the object lists.
   postcondition: Lists are loaded.
*/
template <class T> //Template overloading external load
void load(uniqueListType<T>&, unorderedArrayListType<T>&, uniqueListType<T>&, unorderedArrayListType<T>&, uniqueListType<T>&, unorderedArrayListType<T>&, string); //Prototype for load

int main()
{
   string filename;
   //Instatiating objects
   unorderedArrayListType<string> unorderedWhole; //Full list repeating
   uniqueListType<string> uniqueWhole; //Full list not repeating
   uniqueListType<string> uniqueFirst; //First names not repeating
   unorderedArrayListType<string> unorderedFirst; //First names repeating
   uniqueListType<string> uniqueLast; //Last names not repeating
   unorderedArrayListType<string> unorderedLast; //Last names repeating
   double gain, ticketPrice, profit, cost; //doubles to calculate profit
   cout << fixed << showpoint << setprecision(2);

   //Prompt the user
   cout << "Please enter the name of the data file (Ex: data): ";
   cin >> filename;
   cout << "Please enter the cost per ticket: $";
   cin >> ticketPrice;
   cout << "Please enter the total revenue cost: $";
   cin >> cost;

   load(uniqueWhole, unorderedWhole, uniqueFirst, unorderedFirst, uniqueLast, unorderedLast, filename); //Load lists of all objects

   int maxGrand = uniqueWhole.listSize(); //Upper bound for grand prize
   int maxSmall = unorderedWhole.listSize(); //Upper bound for 4 prizes

   cout << "Number of people who entered: " << uniqueLast.listSize() << endl; //Counting last names of unique list
   cout << "Number of total tickets: " << unorderedFirst.listSize() << endl; //Counting first names of repeating list

   //Print out all objects
   cout << "First and last names of the list: ";
   unorderedWhole.print(); //Print the list
   cout << endl << "First and last names of the list no repeats: ";
   uniqueWhole.print(); //Print the list

   cout << endl << endl << "First names no repeats: ";
   uniqueFirst.print(); //Print the list

   cout << endl << endl << "First names of tickets: ";
   unorderedFirst.print(); //Print the list

   cout << endl << endl << "Last names no repeats: ";
   uniqueLast.print(); //Print the list

   cout << endl << endl << "Last names of tickets: ";
   unorderedLast.print(); //Print the list

   //Pick an odd random number bounded by maxGrand (for grand prize)
   srand(time(0)); //Seeding random generator
   int positionOne = rand()%maxGrand;
   if (positionOne%2 == 0 || positionOne == 0) //Make sure the random number is not 0 or #/2=0
   {
      while (positionOne%2 == 0 || positionOne == 0)
      {
         positionOne = rand()%maxGrand; //Choose a new number
      }
   }
   
   cout << endl << endl << "Winner of PS5: " << uniqueWhole.getAt(positionOne-1) << " " << uniqueWhole.getAt(positionOne) << endl;
   
   int positionTwo = rand()%maxSmall; //Other max of unordered
   if (positionTwo%2 == 0 || positionTwo == 0 || uniqueWhole.getAt(positionOne) == unorderedWhole.getAt(positionTwo)) //Make sure the random number is not 0 or #/2=0
   {
      while (positionTwo%2 == 0 || positionTwo == 0 || uniqueWhole.getAt(positionOne) == unorderedWhole.getAt(positionTwo))
      {
         positionTwo = rand()%maxSmall; //Choose a new number until it is not %2=0, =0, or = name of grandprize winner 
      }
   }
   cout << endl << endl << "Winner of dinner for two at Blue Water Grille: " << unorderedWhole.getAt(positionTwo-1) << " " << unorderedWhole.getAt(positionTwo) << endl;
  
   int positionThree = rand()%maxSmall;
   if (positionThree%2 == 0 || positionThree == 0 || uniqueWhole.getAt(positionOne) == unorderedWhole.getAt(positionThree) || unorderedWhole.getAt(positionTwo) == unorderedWhole.getAt(positionThree))
   {
      while (positionThree%2 == 0 || positionThree == 0 || uniqueWhole.getAt(positionOne) == unorderedWhole.getAt(positionThree) || unorderedWhole.getAt(positionTwo) == unorderedWhole.getAt(positionThree))
      {
         positionThree = rand()%maxSmall; //Choose a new number until it is not %2=0, =0, or = to the name of the previous winners
      }
   }
   cout << endl << endl << "Winner of the set of 4 passes to Wet N Wild: " << unorderedWhole.getAt(positionThree-1) << " " << unorderedWhole.getAt(positionThree) << endl;

   int positionFour = rand()%maxSmall;
   if (positionFour%2 == 0 || positionFour == 0 || uniqueWhole.getAt(positionOne) == unorderedWhole.getAt(positionFour) || unorderedWhole.getAt(positionTwo) == unorderedWhole.getAt(positionFour) || unorderedWhole.getAt(positionThree) == unorderedWhole.getAt(positionFour))
   {
      while (positionFour%2 == 0 || positionFour == 0 || uniqueWhole.getAt(positionOne) == unorderedWhole.getAt(positionFour) || unorderedWhole.getAt(positionTwo) == unorderedWhole.getAt(positionFour) || unorderedWhole.getAt(positionThree) == unorderedWhole.getAt(positionFour))
      {
         positionFour = rand()%maxSmall; //Choose a new number until it is not %2=0, =0, or = to the name of the previous winners
      }
   }   
   cout << endl << endl << "Winner of $100 amazon gift card: " << unorderedWhole.getAt(positionFour-1) << " " << unorderedWhole.getAt(positionFour) << endl;

   int positionFive = rand()%maxSmall;
   if (positionFive%2 == 0 || positionFive == 0 || uniqueWhole.getAt(positionOne) == unorderedWhole.getAt(positionFive) || unorderedWhole.getAt(positionTwo) == unorderedWhole.getAt(positionFive) || unorderedWhole.getAt(positionThree) == unorderedWhole.getAt(positionFive) || unorderedWhole.getAt(positionFour) == unorderedWhole.getAt(positionFive))
   {
      while (positionFive%2 == 0 || positionFive == 0 || uniqueWhole.getAt(positionOne) == unorderedWhole.getAt(positionFive) || unorderedWhole.getAt(positionTwo) == unorderedWhole.getAt(positionFive) || unorderedWhole.getAt(positionThree) == unorderedWhole.getAt(positionFive) || unorderedWhole.getAt(positionFour) == unorderedWhole.getAt(positionFive))
      {
         positionFive = rand()%maxSmall; //Choose a new number until it is not %2=0, =0, or = to the name of the previous winners
      }
   }
   cout << endl << endl << "Winner of the set of 4 movie passes at the Palladium Regal Theater: " << unorderedWhole.getAt(positionFive-1) << " " << unorderedWhole.getAt(positionFive) << endl << endl;
   gain = ticketPrice*unorderedFirst.listSize(); //Gain is = to the price of the ticket times the number of tickets bought
   profit = gain-cost; //Profit is equal to gain - cost
   if (profit <= 0) //If profit is negative or 0 there was no profit
      cout << "There was no profit. You are $" << cost-gain << " away from breaking even." << endl;
   else
      cout << "Total profit: $" << profit << endl;
   return 0;
} //End main

template <class T>
void load(uniqueListType<T> &uniqueWholePass, unorderedArrayListType<T> &unorderedWholePass, uniqueListType<T> &uniqueFirstPass, unorderedArrayListType<T> &unorderedFirstPass, uniqueListType<T> &uniqueLastPass, unorderedArrayListType<T> &unorderedLastPass, string file)
{
   ifstream inFile;
   inFile.open(file);
   string temp;
   inFile >> temp; //Storing it into a temp
   while (!inFile.eof() && !uniqueWholePass.isFull() && !unorderedWholePass.isFull() && !unorderedFirstPass.isFull() && !uniqueFirstPass.isFull() && !uniqueLastPass.isFull() && !unorderedLastPass.isFull()) //While the file is not at the end and the lists are not full
   {
      uniqueFirstPass.insertEnd(temp); //Insert the string into lists (first name)
      unorderedFirstPass.insertEnd(temp);
      uniqueWholePass.insertEnd(temp);
      unorderedWholePass.insertEnd(temp);
      inFile >> temp;
      uniqueWholePass.insertEnd(temp); //Insert the string into lists (last name)
      unorderedWholePass.insertEnd(temp);
      uniqueLastPass.insertEnd(temp);
      unorderedLastPass.insertEnd(temp);
      inFile >> temp;
   }
   inFile.close();
}
