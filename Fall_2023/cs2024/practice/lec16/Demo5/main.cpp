//
// CS2024 Lecture 16, Demo 4
//
// Template Classes
//

#include <iostream>

using namespace std;

#include "MyArray.h"

int main(int argc, char * argv[])
{
    // Declare a new template class instance of type MyArray<int>
    MyArray<int,5> myArray;

    // Inialize all 5 entries
    for (int i=0; i<5; i++)
        myArray[i]=i;

    // Print out entires. Purposley go one too far and see where exception comes out
    for (int j=0; j<=5; j++)
    {
        cout << "Element #" << j << " is: "  << myArray[j] << endl;
    }
}