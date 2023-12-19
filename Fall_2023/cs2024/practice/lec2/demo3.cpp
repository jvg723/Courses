// 
// CS 2024 -- Lecture #2
// 
// Demo #3 -- Big, ugly, if-else statement
//

#include <iostream>

using namespace std; // allows us to use cout, cin, endl without std:: prefix

int main(int argc, char *argv[])
{
    int x;

    cout << "Enter a numer> ";
    cin >> x;       // read input into x

    if (x == 0)
        cout << "x is zero" << endl;
    else if (x == 1)
        cout << "x is one" << endl;
    else if (x == 2)
        cout << "x is two" << endl;
    else
        cout << "x is not 0,1 or 2" << endl;

    return 0; 

}