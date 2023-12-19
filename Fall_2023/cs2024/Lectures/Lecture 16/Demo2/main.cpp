//
// CS2024:  Lecture #16, Demo 2
//
// Simplifying MyString
//

#include <iostream>
//#include <utility>
using namespace std;  //introduces namespace std
using namespace rel_ops;

#include "MyString.h"

int main()
{	
    MyString str1("S");
    MyString str2("T");
    
    if (str1 <= str2)
		cout << str1 << " is less than or equal to " << str2 << endl;
    else
		cout << str1 << " is greater than " << str2 << endl;	
    if (str1 != str2)
		cout << str1 << " is not equal to " << str2 << endl;
    else
		cout << str1 << " is equal to " << str2 << endl;
	return 0;
}

