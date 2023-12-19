// 
// CS 2024 -- Lecture #5
// 
// Demo #8 -- Counter Class
//
#include <iostream>
#include <string>
#include "Counter.h"

using namespace std;

int main(int argc, char * argv[])
{
        Counter x;
        Counter y(5);

        cout << "x has value: " << x.getCounter() << endl;
        cout << "y has value: " << y.getCounter() << endl;

    return 0;
}