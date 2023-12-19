//
// CS2024:  Lecture #8, Demo #5
//
// MyString String Class
//

#include <iostream>

using namespace std;  //introduces namespace std

#include "MyString.h"

int main()
{
  MyString str("Hello There World");

  cout << "str is : " << str.MakeString() << endl;
  cout << "character at position 10 is: " << str.charAt(10) << endl;

  MyString *anotherStr = new MyString("goodbye");
  
  cout << "another string is: " << anotherStr->MakeString() << endl;

  anotherStr->charAt(0) = 'G';

  cout << "another string is: " << anotherStr->MakeString() << endl;

  delete anotherStr;
}

