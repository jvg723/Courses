//
// CS2024:  Lecture #9, Demo #3
//
// Overloading []
//

#include <iostream>

using namespace std;  //introduces namespace std

#include "MyString.h"

int main()
{
	MyString str1("This is a test 😁");
	str1[2] = 'u';
	
	cout << "str1 is: "  << +str1 << endl;

	cout << "str1[15] is " << str1[15] << endl;
}

