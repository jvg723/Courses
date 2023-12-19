// 
// CS 2024 -- Lecture #7
// 
// Demo #3 -- C String Library calls
//

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main (int argc, char *argv[])
{
    // Declare two C style strings
    char *str1 = "Hello";
    char *str2 = "World";

    char str3[40];

    // Call strlen on str1
    cout << "length of str1 is " << strlen(str1) << endl;

    // Now compare str1 and str2
    cout << "strcpy on str1 and str2 produces: " << strcmp(str1,str2) << endl;

    // Now, copy str1 into str2
    strcpy(str3,str1);
    cout << "str3 is " << str3 << endl;
}