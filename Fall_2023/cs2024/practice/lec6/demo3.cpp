// 
// CS 2024 -- Lecture #6
// 
// Demo #3 -- Pointer Chaos
//
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int *a = NULL, *b = NULL;

    a = new int; // Allocate a new int variable and store pointer to it in a
    b = new int; // Allocate a new int variable and store pointer to it in b

    // Store values in the memory pointed at by a and b 
    *a = 5;
    *b = 7;

    cout << "*a is " << *a << " and *b is " << *b << endl;

    // Put what is stored in the memory pointed at by a
    // into the memory pointed at by b
    *b = *a;
    cout << "*a is " << *a << " and *b is " << *b << endl;

    // Now store the memory address stored in the pointer variable a
    // into the pointer variable b
    b = a;
    *b = 8;
    cout << "*a is " << *a << " and *b is " << *b << endl;

    delete a;
    delete b;

    return 0;
}