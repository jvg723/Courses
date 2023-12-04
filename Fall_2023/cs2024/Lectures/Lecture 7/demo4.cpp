//
// CS2024 -- Lecture #7
//
// Demo #4 -- C++ String method calls
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
	// Declare two C style strings
	string str1 = "Hello";
	string str2 = "World";
	string str3;
		
	// Call length on str1
	cout << "length of str1 is " << str1.length() << endl;
	
	// Now, compare str1 and str2
	cout << "compare on str1 and str2 produces: " << str1.compare(str2) << endl;
	
	// Now, copy str1 into str3
	str3 = str1;
	cout << "str3 is " << str3 << endl;
}

