// 
// CS 2024 -- Lecture #3
// 
// Demo #5 -- squareIt()

#include <iostream>
using namespace std;

// We would need a "forward decleration" if we move the
// squareIt implementation "below" main

long squareIt(long);

int main(int argc, char *argv[])
{
    long y;
    cout << "Enter a value to be squared> " << endl;
    cin >> y;

    long result = squareIt(y);
    cout << y << " squared is " << result << endl;

    return 0;
}

// squareIt() can be declared as pass by reference or pass by value
// pass by VALUE:     long squareIt(long x)
// pass by REFERENCE: long squareIT(long &x)
long squareIt(long x)
{
    x *= x; // remeber, this is like x = x * x;
    return x;
}