//
// CS2024:  Lecture #22, Demo #7
//
// setprecision,  precision
//

#include <iostream>
#include <iomanip>

using namespace std;

int main (int argc, char * const argv[])
{
    int curPrecision = cout.precision(); // with 0 args returns current setting
    cout << "Current precision is " << curPrecision << " decimal places " << endl;

    // If you've never called setprecision before, you will get 6 significant digits
    // with NO trailing zeroes
    cout << 3.12 << endl;
    cout << 3.12545 << endl;
    cout << 3.11111111111111111 << endl;

    // Print out only 2 decimal places
    cout << fixed << setprecision(2) << 3.12545 << endl;

    // HOWEVER, once you've used the fixed manipulator, you will always get
    // trailing zeroes to make sure the number of digits after the decimal
    // place will match the number specified by setprecision

    // Restore original setting
    cout.precision(curPrecision);

    // Print out again to show how many decimal places show after restoring
    // the original precision
    cout << 3.12545 << endl;
    cout << 3.12 << endl;

    // What about scientific?
    cout << scientific << 3.12545 << endl;

    return 0;
}