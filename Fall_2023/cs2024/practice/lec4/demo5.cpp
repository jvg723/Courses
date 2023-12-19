// 
// CS 2024 -- Lecture #4
// 
// Demo #5 -- Writting to Basic Arrays

#include <iostream>
using namespace std;

// Simple test of arrays
int main (int argc, char *argv[])
{
    // Declare an array of primes
    int iArray[8];

    // Initialize the array
    for (int k = 0; k < 8; k++)
        iArray[k] = k;

    // Assign a new value into the array
    iArray[4] = 15;

    // Print out the second array
    for (int j = 0; j < 8; j++)
        cout << "iArray[" << j << "] is " << iArray[j] << endl;

    return 0;
}