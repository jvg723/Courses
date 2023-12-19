//
// CS2024 Lecture #18, Demo #2
//
// static_cast<>
//

#include <iostream>
using namespace std;

int main (int argc, char * const argv[]) 
{
    int x = 5, y = 2;
    int *iPtr;

    // Remember, when the compiler divides two integers, it
	// does integer arithmetic
    cout << " 5/2 is: " << x/y << endl;

    // I can use static_cast<> to cast these values to floats
	// (or doubles) so that I can perform floating point division
    cout << "static_cast<float>(x)/static_cast<float>(y) is: "
         <<  static_cast<float>(x)/static_cast<float>(y) << endl;

    // static_cast<> will do some type checking.  If there isn't
	// a legal way to convert from one type to another, a compiler
	// error will result.  (Comment out the following line to compile file)
    // iPtr = static_cast<int *>(x);

    // Doing the same thing with an older  C style cast
	// produces no errors (but does produce warnings)
    iPtr = (int *) x;
    return 0;
}