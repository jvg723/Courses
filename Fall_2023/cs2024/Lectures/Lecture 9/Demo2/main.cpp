//
// CS2024:  Lecture #9, Demo #2
//
// Binary Operator Overloads
//

#include <iostream>
#include <string>

using namespace std;  //introduces namespace std

#include "MyString.h"

int main()
{
	MyString str1("This is an");
	MyString str2(" overloaded binary operation");
	//MyString str3(+(str1 + str2));
	MyString str3 = str1 + str2;
	cout << "str3 is: " << +str3 << endl;
}

