/*
   Ryan Hirscher
   csc1720
   /home/students/rhirscher/csc1720/prog5/studentType.h
   4/28/2021

   This file is the headerfile and implementation file for the class stuType where it is a dataType that contains first name, last name, and GPA. This information is bundled and used inside a linked list class for order and other processes. This class overloads several operators so that actions can be used according to the GPA private variable.

*/
#ifndef STUDENT_TYPE
#define STUDENT_TYPE
class stuType
{
   private:
      double GPA;
      string first;
      string last;
   public:
      //Constructor stuType
      stuType();

      //setGPA is used to pass a value in load to set the private variable GPA
      //Postcondition: GPA is set by passed value
      void setGPA(double);

      //getGPA is used to return the GPA of each student using an iterator
      //Postcondition: GPA is returned to main
      double getGPA();

      //setFirst is used to pass a string in load to set the private variable first
      //Postcondition: first is set according to pass value
      void setFirst(string);

      //setLast is used to pass a string in load to set the private variable last
      //Postcondition: last is set according to pass value
      void setLast(string);

      //friend function overloads operator << to appropriately output the information in each bundle
      //of stuType
      //Postcondition: Information of that student is outputted to the terminal
      friend ostream& operator<<(ostream&, const stuType&); //Friend for 2 arguments

      //Operator == is overloaded returning true if GPA is equal and false if not
      //Precondition: Unable to compile because of search, insert, and other operations
      //Postcondition: Operations of other classes will work
      bool operator==(const stuType&) const; 
 
      //Operator != is overloaded returning true if GPA is not true and false if not
      //Precondition: Unable to compile because of search, insert, and other operations
      //Postcondition: Operations of other classes will work
      bool operator!=(const stuType&) const;

      //Operator >= is overloaded returning true if GPA is greater than or equal to and false if not
      //Precondition: Unable to compile because of search, insert, and other operations
      //Postcondition: Operations of other classes will work
      bool operator>=(const stuType&) const;

      //Operator <= is overloaded returning true if GPA is less than or equal to and false if not
      //Precondition: Unable to compile because of search, insert, and other operations
      //Postcondition: Operations of other classes will work
      bool operator<=(const stuType&) const;

      //Operator < is overloaded returning true if GPA is less than and false if not
      //Precondition: Unable to compile because of search, insert, and other operations
      //Postcondition: Operations of other classes will work
      bool operator<(const stuType&) const;

      //Operator > is overloaded returning true if GPA is greater than and false if not
      //Precondition: Unable to compile because of search, insert, and other operations
      //Postcondition: Operations of other classes will work
      bool operator>(const stuType&) const;

};
stuType::stuType()
{
   GPA = 0;
   first = "";
   last = "";
}

void stuType::setGPA(double temp)
{
   GPA = temp;
}

ostream& operator<<(ostream &os, const stuType &student)
{ //Builds an os string and returns it
   os << student.GPA << " ";
   os << student.first << " ";
   os << student.last << " ";
   return os;
}

bool stuType::operator==(const stuType &right) const
{
   return (GPA == right.GPA);
}

bool stuType::operator!=(const stuType &right) const
{
   return (GPA != right.GPA);
}

bool stuType::operator>=(const stuType &right) const
{
   return (GPA >= right.GPA);
}

bool stuType::operator<=(const stuType &right) const
{
   return (GPA <= right.GPA);
}

bool stuType::operator<(const stuType &right) const
{
   return (GPA < right.GPA);
}

bool stuType::operator>(const stuType &right) const
{
   return (GPA > right.GPA);
}

double stuType::getGPA()
{
   return GPA;
}

void stuType::setFirst(string temp)
{
   first = temp;
}

void stuType::setLast(string temp)
{
   last = temp;
}
#endif
