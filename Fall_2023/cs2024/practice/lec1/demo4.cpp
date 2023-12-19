//
// CS 2023 -- Lecture #1
// Demo #4: using string variable with getline
//

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;  // Some compilers have string definitions include from iostream

// Here's our main function
int main (int argc, char * const argv[])
{
    string stringVariable;

    cout << "Please enter a string: " << endl;
    getline(cin,stringVariable);  // getline is a global function

    cout << "You entered: " << stringVariable << endl;

    return 0; 
}