//
// CS2024 -- Lecture #7
//
// Demo #1 -- Arguments to main()
//

#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
	cout << "You really need to execute this from a command line to fully understand :-)\n";
	
	// Go through all arguments passed on the command line and print them out!
	for (int i=0; i<argc; i++)
		cout << "Argument " << i << " is " << 
		argv[i] << endl;
	
}
