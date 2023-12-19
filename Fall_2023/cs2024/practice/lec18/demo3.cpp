//
// CS2024 Lecture #18, Demo #3
//
// reinterpret_cast<>
//

#include <iostream>
using namespace std;

int main (int argc, char * const argv[])
{
    int x = 5;
    int *iPtr;

    // reinterpret_cast<> will NOT do type checking.  
	// The following code is considered legal, though
	// it will have very bad results!
    iPtr = reinterpret_cast<int *>(x);
    *iPtr = 10;

    return 0;
}