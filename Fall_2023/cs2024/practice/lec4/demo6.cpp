// 
// CS 2024 -- Lecture #4
// 
// Demo #6 -- Enumerations

#include <iostream>
using namespace std;

// Here's an enumeration for "JoesError"
enum JoesError
{
    cNoError = 0,   // Values are optional, default initial
    cBadArg,        // value is 0
    cBadResult,     // If a value is not present
    cUnknownErr,    // assign previous value + 1
};

// Here's an arbitray function to test out our enumeration
JoesError JoesFunction()
{
    return cBadResult;
}

// We test out our enumeration in the main() function 
int main(int argc, char *argv[])
{
    JoesError jerr = JoesFunction(); // An arbitrary function
    if (jerr != cNoError)
        cerr << "Ooooops, Error:" << jerr << endl;
    else
        cout << "No error" << endl;
    
    // If we uncomment this line, we'll get an error
    //jerr = 1;
}