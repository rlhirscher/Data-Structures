#include <iostream>
int main()
{
 int a = 5;
 int alias = a;
 int *ptr = &a;
 alias++;
 std::cout << "*ptr = " << *ptr << "\n";
 a++;
 std::cout << "*ptr = " << *ptr << "\n";
 return 0;
}
