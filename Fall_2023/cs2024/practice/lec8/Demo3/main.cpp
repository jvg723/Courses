//
// CS2024:  Lecture #8, Demo #3
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

  // Read the string from the keyboard.   What happens if we use an emoji?
  str.readString(45);
  cout << "You entered... " << str.MakeString() << endl << endl;

  // What happens if we don't enter a string that has at least 11 characters?
  cout << "character at position 10 is: " << str.charAt(10) << endl;
}

