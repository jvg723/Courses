// 
// CS 2024 -- Lecture #5
// 
// Demo #7 -- Counter Class
//
#include <iostream>
#include <string>
#include "Counter.h"

using namespace std;

int main(int argc, char *argv[])
{
    Counter x;

    cout << "x has value: " << x.getCounter() << endl;

    x.increment();

    cout << "x now has value: " << x.getCounter() << endl;

return 0;
}