//
// CS2024:  Lecture #8, Demo #4
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

  MyString *anotherStr = new MyString("goodbye, this is a really long string to illustrate the concept of dynamic memory allocation within MyString");
  
  cout << "another string is: " << anotherStr->MakeString() << endl;
  delete anotherStr;
  cout << "End?" << endl;
}

