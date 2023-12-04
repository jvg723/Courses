//
// CS2024 -- Lecture #3
//
// Demo #6 -- Pass by reference with and without the const keyword
//

#include <iostream>
using namespace std;  

// If we were to put the definition of squareIt() underneath main(),
// we'd need a forward declaration

// COMPILATION ERROR WILL RESULT IF PASS-BY-REFERENCE VARIABLE IS DECLARED AS CONST!
long squareIt(long &x)    // pass by reference
//long squareIt(const long &x)   // pass by reference w/const protection
{
	x *= x;    // remember, this is like x = x * x;
	return x;
}

int main(int argc, char *argv[])
{	
	long y;
	cout << "Enter a value to be squared> ";
	cin >> y;
	
	long result = squareIt(y);
	cout << y << " squared is " << result << endl;
	
	return 0;
}

