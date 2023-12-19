// 
// CS 2024 -- Lecture #4
// 
// Demo #4 -- Basic Arrays

#include <iostream>
using namespace std;

// Simple test of arrays
int main(int argc, char *argv[])
{
    // Declar an array of primes
    int smallPrimes[7] = {2,3,5,7,11,13,17};
    int countByFives[] = {5,10,15,20,25,30,35};

    // Print out the array
    for (int k = 0; k < 7; k++)
        cout << "smallPrimes[" << k << "] is " << smallPrimes[k] << endl;
    
    // Print out the second array 
    for (int j = 0; j < 7; j++)
        cout << "countByFives[" << j << "] is " << countByFives[j] << endl;

    return 0;
}