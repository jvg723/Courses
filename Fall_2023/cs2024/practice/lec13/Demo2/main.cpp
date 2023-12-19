// CS2024:  Lecture #9, Demo #6
//
// Demonstrate use of delegating constructor
//

#include <iostream>
#include <string>  // required for Visual Studio
using namespace std;  //introduces namespace std

#include "MyString.h"

int main()
{
  MyString str("Hello World!");
  cout << "str is " << str << endl;
}
