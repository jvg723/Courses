//
// CS2024:  Lecture #8, Demo #2
//
// MyString String Class
//

#include <iostream>

using namespace std;  //introduces namespace std

#include "./mystring/Mystring.h"

int main()
{
  MyString str;
  cout << "Enter a string> ";
  str.readString(45);
  cout << "You entered... " << str.MakeString() << endl << endl;
}

