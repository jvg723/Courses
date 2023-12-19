// 
// CS 2024 -- Lecture #4
// 
// Demo #1 -- Function Templates

#include <iostream>
using namespace std;

// Here's a function template for the maximum function!
template <typename T>
T maximum(T val1, T val2, T val3)
{
    T maxValue = val1;

    // Is val2 bigger than val1?
    if (val2 > maxValue)
        maxValue = val2;

    //Is val3 bigger than maxValue (now either val1 or val2)
    if (val3 > maxValue)
        maxValue = val3;

    return maxValue;
}

// now, a main() function to test this out
int main(int argc, char *argv[])
{
    int x = 5, y = 2, z = 8;
    char c1 = 'a', c2 = 'b', c3 = 'c';
    float f1 = 3.14, f2 = 0.03, f3 = 2.2;

    cout << "maximum int is: " << maximum(x,y,z) << endl;
    cout << "maximum char is: " << maximum(c1,c2,c3) << endl;
    cout << "maximum float is: " << maximum(f1,f2,f3) << endl;

    return 0;
}