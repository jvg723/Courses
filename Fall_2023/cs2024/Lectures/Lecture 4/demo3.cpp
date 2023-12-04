//
// CS2024 -- Lecture #4
//
// Demo #3 -- Default Arguments
//

#include <iostream>

using namespace std;

// A silly global function to allow us to increment an integer argument
// The incrementBy takes a *default argument* value of 1
void increment(int &arg,int incrementBy=1) {
  arg += incrementBy;
}

int main (int argc, char *argv[]) 
{
    int x=0;

    // Print initial value of x
    cout << "x has value: " << x << endl;

    // Increment by 3 (so we specify 3 as the second parameter)
    increment(x,3);
    cout << "x has value: " << x << endl;

    // Increment by 1 (utilize default value of second parameter
    // by not passing it)
    increment(x);
    cout << "x has value: " << x << endl;

    return 0;
}
