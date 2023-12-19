// 
// CS 2024 -- Lecture #7
// 
// Demo #1 -- Arguments to maim()
//
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    cout << "You really need to execute this from a command line to fully understand :-)\n";

    // Go through all arguments passed on the command line and print them out!
    for (int i=0; argc; i++)
        cout << "Arguments " << i << " is " <<
        argv[i] << endl;
}