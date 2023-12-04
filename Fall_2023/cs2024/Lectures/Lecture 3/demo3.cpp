//
// CS2024 -- Lecture #3
//
// Demo #3 -- Miscellaneous Scope Issues
//

#include <iostream>
using namespace std;  

// Declare a global variable named "globalX"
int globalX = 0;

int main(int argc, char *argv[])
{	
	// declare some local variables
	int x = 0,y = 1,k = 5;
	{
		// We're in a new scope here, the variable declared
		// below is local to this scope
		int x = 1;
		
		x = 10;
		
		// We can still access y because it is in a "parent" scope
		cout << "x is " << x << ", y is " << y << endl;
		
		// We can still access globalX because it is in a "global" scope
		globalX = 10;
	}
	
	cout << "x is " << x << " and k is " << k << endl;
	cout << "globalX is " << globalX << endl;
	
	return 0;
}

