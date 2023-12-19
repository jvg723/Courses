//
// CS2024:  Lecture #8, Demo #1
//
// MyString String Class
//

#include <iostream>

using namespace std;  //introduces namespace std

#include "MyString.h"

int main()
{
  MyString str;
  cout << "Enter a string> ";
  str.readString(45);
  cout << "You entered... " << str.MakeString() << endl << endl;
}