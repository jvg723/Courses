//
// CS2024 -- Lecture #3
//
// Demo #5 -- squareIt()
//

#include <iostream>
using namespace std;  

// We would need a "forward declaration" if we moved the 
// squareIt implementation "below" main

long squareIt(long&);


int main(int argc, char *argv[])
{	
	long y;
	cout << "Enter a value to be squared> ";
	cin >> y;
	
	long result = squareIt(y);
	cout << y << " squared is " << result << endl;
	
	return 0;
}

//  squareIt() can be declared as pass by reference or pass by value
//  Pass by VALUE:     long squareIt(long x)
//  Pass by REFERENCE: long squareIt(long &x)
long squareIt(long &x)   
{
	x *= x;    // remember, this is like x = x * x;
	return x;
}
