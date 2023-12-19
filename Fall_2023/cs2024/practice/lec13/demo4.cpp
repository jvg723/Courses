//
// CS2024:  Lecture #13, Demo 4
//
// Array Initializations and const
//

#include <iostream>
#include <array>

using namespace std;

int main(int argc, char *argv[])
{
    // Declare an arbitrary array
    int x = 0;
    int y = 0;
    int z = 5;
    array<int,5> someArray{1,2,3,4,5};

    // ADVANCED TOPIC:  Because of the order in which I've declared the variables
    // above AND because there is no bounds checking on someArray, if I try to
    // access someArray[5] it will be the same as accessing local variable z.
    // someArray[6] is like local variable y
    // someArray[7] is like local varaible x
    // Anything higher than 7 could start *really* corrupting the stack and result
    // in crashes

    // Try to access the element at position 6
    cout << "someArray[6] is " << someArray[6] << endl;

    // Wait, how big is the array?
    cout << "size of someArray is " << someArray.size() << endl;

    // What element number whould you like to wite "6" to?
    int index;
    cout << "Enter an element number to write integer 6 to: ";
    cin >> index;

    // Warning! This could crash if index in not "in bounds"
    someArray[index] = 6;

    // Print out the element
    cout << "someArray [" << index << "] is " << someArray[index] << endl;

    cout << "x is " << x << endl;
    cout << "y is " << y << endl;
    cout << "z is " << z << endl; 
}