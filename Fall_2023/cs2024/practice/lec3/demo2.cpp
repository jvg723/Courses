// 
// CS 2024 -- Lecture #3
// 
// Demo #2: Implicit Type Coercion

#include <iostream>
#include <cmath>

using namespace std;

// printMyName takes a "signed short"
// can hold number between -32768 and 32767
void printMyName(short n)
{
    for (int i=0; i<n; i++)
    {
        cout << "Joe Giliberto" << endl;
    }
}

int main(int argc, char *argv[])
{
    short i=5;
    // The following is how you'd initialize a hexadecimal number
    long long j = 0x56760003;
    float f = 3.145;
    int x;

    cout << "Calling printMyName with i=" << i << endl;
    printMyName(i);
    cin >> x; 

    // \n in string below causes a newline to be printed
    cout << "\n\nCalling printMyName with j=" << j << endl;
    printMyName(j);
    cin >> x;

    // \n in string below causes a newline to be printed
    cout << "\n\nCalling printMyName with f=" << f << endl;
    printMyName(f);
    cin >> x;

    // Demonstrate use of cmath function
    cout << "\n\nCalling printMyName with ceil(f)" << endl;
    printMyName(ceil(f));
}