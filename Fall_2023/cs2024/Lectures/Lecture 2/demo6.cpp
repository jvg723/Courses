//
// CS2024 -- Lecture #2
//
// Demo #6 -- The continue statement
//

#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
	// Print my name 10 times the hard way
	
	for (int i=0; i<20; i++)
	{
		// if the floating point value of i/2 is equal to the integer value
		// of i/2, this is an even number.
	        if ((float) i/2 == i/2)
			continue;  // skip the even numbers by going right back to the start of the loop
		
		// The above statement COULD NOT be written as if ((float) (i/2) == (i/2))

		// If we're here, it must be an odd number, print my name!
		cout << "i is " << i << " and my name is Ron!" << endl;
	}
	
    return 0;
}
