//
// CS2024:  Lecture #9, Demo #5
//
// Overloading the assignment operator
//

#include <iostream>

using namespace std;  //introduces namespace std

#include "MyString.h"

int main()
{
  // Create a couple of MyString variables
  MyString str1("This is a test 😄");
  MyString str2("Another test");

  cout << "str2 before assignment is: " << +str2 << endl;

  // Using our overloaded operator=.   Emojis will work here because they get
  // translated into C++ strings which can handle emojis without issue.
  str2 = str1;
  cout << "str2 after assignment is:  " << +str2 << endl;

  MyString str3(str2);
  MyString str4 = str1;

	cout << "str3: " << +str3 << endl;
	cout << "str4: " << +str4 << endl;
}

