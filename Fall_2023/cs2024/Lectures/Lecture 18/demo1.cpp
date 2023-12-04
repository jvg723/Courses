//
// CS2024 Lecture 18, Demo #1
//
// C-style and original C++ style casting
//

#include <iostream>
using namespace std;

int main (int argc, char * const argv[]) {
    int x = 5, y = 2;
	
	// Show that dividing x by y without casting results in integer division
	float f = x/y;
	
	cout << "f is: " << f << endl;
	
	// Now cast them the C-style way
	float f1 = (float) x / (float) y;
	
	cout << "f1 is: " << f1 << endl;
	
	// Now cast them the original C++ way
	float f2 = float(x)/float(y);
	
	cout << "f2 is: " << f2 << endl;
    return 0;
}
