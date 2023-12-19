//
// CS2024:  Lecture #9, Demo 1
//
// Unary Operator Overloads
//

#include <iostream>

using namespace std;  //introduces namespace std

#include "MyString.h"

int main()
{
  MyString aStr("This is a test");
  MyString bStr("This is a 😆");
  cout << "The string '" << +aStr << "' has a length of " << ~aStr << endl;
  cout << "The string '" << +bStr << "' has a length of " << ~bStr << endl;
}

