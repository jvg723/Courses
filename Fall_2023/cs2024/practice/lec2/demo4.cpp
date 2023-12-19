// 
// CS 2024 -- Lecture #2
// 
// Demo #4 -- Using a switch statement

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int x;

    cout << "Enter a number> ";
    cin >> x;   // Read in an integer into the x variable

    // Use a swtich statement to execure different code
    // depdending on the value of x
    switch(x)
    {
        case 0:
                // Execute if x == 0
                cout << "x is zero " << endl;
                break;
        case 1:
                // Excute if x == 1
                cout << "x is one" << endl;
                break;
        case 2: 
                // Execute if x == 2
                cout << "x is two" << endl;
                break;
        default:
                // Execute if x is not 0,1 or 2
                cout << "x is not 0,1 or 2" << endl;
                break;
    }
    return 0;
}