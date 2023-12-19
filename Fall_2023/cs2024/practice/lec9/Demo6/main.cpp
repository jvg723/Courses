// CS2024:  Lecture #9, Demo #6
//
// overloading operator<< and operator>>
//

#include <iostream>
#include <string>  // required for Visual Studio
using namespace std;  //introduces namespace std

#include "MyString.h"

int main()
{
  MyString str;

  cout << "Enter a string: ";
  cin >> str;

  cout << "str is " << str << endl;
  
  cout << "Enter another string: ";
  MyString str2;

  cin >> str2;
  cout << "str2 is " << str2 << endl;
}
