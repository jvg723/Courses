// 
// CS 2024 -- Lecture #4
// 
// Demo #2 -- Recursion

#include <iostream>
using namespace std;

// Here is our recursive defintion of factorial
unsigned long factorial(unsigned long number)
{
    if (number <= 1)
        return 1;
    else
        return number * factorial(number-1);
}

int main (int argc, char *argv[])
{
        // we need an input variable
        unsigned long i;

        // prompt for a number 
        cout << "Compute factorial for what number? ";
        cin >> i;

        cout << i << "! is " << factorial(i) << endl;

    return 0; 
}