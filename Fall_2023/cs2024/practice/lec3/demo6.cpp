// 
// CS 2024 -- Lecture #3
// 
// Demo #6 -- Pass by reference with and without the const keyword

#include <iostream>
using namespace std;

// If we were to put the defintion of squareIt() underneath main(),
// we'd need a forward decleration

// COMPILATION ERROR WILL RESULT IF PASS-BY-REFERENCE VARIABLE IS DECLARED CONST!
// long squareIt(long &x)  // pass by reference 
long squareIt(const long &x) // oass by reference with const protection
{
    x *= x; // remeber, this is like x = x * X
    return x;
}

int main(int argc, char *argv[])
{
    long y;
    cout << "Enter a value to be sqaured> ";
    cin >> y;

    long result = squareIt(y);
    cout << y << " squared is " << result << endl; 

    return 0;
    
}