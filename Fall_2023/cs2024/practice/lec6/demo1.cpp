// 
// CS 2024 -- Lecture #6
// 
// Demo #1: Pointers with Dynamic Allocation
//
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    // Declare a new pointer iPtr and allocate space for one integer
    int *iPtr = new int;
    
    // Make sure allocation is succeeded 
    if (iPtr == NULL)
    {
        cout << "Could not allocate pointer, bye!";
        return -1;
    }

    *iPtr = 5; // Will actually write data into memory
    cout << "iPtr is " << iPtr << " and *iPtr is " << *iPtr << endl;

    delete iPtr; // This is how you dispose of a pointer 
    return 0;
}