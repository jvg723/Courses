//
// CS2024 -- Lecture #4
//
// Demo #6 -- Enumerations
//

#include <iostream>

using namespace std;

// Here's an enumeration for "RonsError"
enum RonsError
{
	cNoError = 0,   // Values are optional, default initial
	cBadArg,        //          value is 0
	cBadResult,     // If a value is not present, 
	cUnknownErr     //   assign previous value + 1
};


// Here's an arbitrary function just to test out our enumeration
RonsError RonsFunction()
{
	return cBadResult;
}



// We test out our enumeration in the main() function
int main(int argc,char *argv[])
{
	RonsError rerr = RonsFunction();  // An arbitrary function
	if (rerr != cNoError)
		cerr << "Ooooops, Error:" << rerr << endl;
	else
		cout << "No error" << endl;
	
	//If we uncomment this line, we'll get an error!  
	//rerr = 1;
}
