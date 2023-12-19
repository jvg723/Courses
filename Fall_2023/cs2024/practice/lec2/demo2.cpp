// 
// CS 2024 -- Lecture #2
// 
// Demo #2 -- Arithemtic Shortcuts, Pre/Postfix operators
//

#include <iostream>

using namespace std; // allows us to use cout, cin, endl without std:: prefix

int main(int argc, char * argv[])
{
    // Declare a couple of integer varaibles and assign values
    int x = 5;
    int y = 3;

    // Declare an integer varaible to hold a result in
    int result;

    // Add x and y
    result = x + y;

    // Print out the result 
    cout << "Result is " << result << endl;

    // Use the += shortcut with the result variable and print out the result
    result += 5;
    cout << "Result is " << result << endl;

    // Declare two new result variables to demonstrate the use of 
    // pre and post fix ++
    int result2 = result ++;

    cout << "result is " << result << endl;
    int result3 = ++result;

    // Print out the results of the pre and postfix ++
    cout << "result2 is " << result2 << " and result3 is " << result3 << endl;

    return 0;
}