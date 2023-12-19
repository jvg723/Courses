// 
// CS 2024 -- Lecture #7
// 
// Demo #2 -- Using sizeof()
//
#include <iostream>
#include <string>
using namespace std;

//
// Here's a funciton that takes an array and attempts to print out
// the size of an array
//
void printArraySize(int array[])
{
	cout << "printArraySize(): Array size is: " << sizeof(array) << endl;
}

int main(int argc, char *argv[])
{
    // Declare an integer array
    int intArray[7];
    int anotherIntArray[] = {1,2,3,4,5,6};

    // Call sizeof() directly on the array variables that were statically declared
    cout << "sizeof(intArray) is " << sizeof(intArray) << endl;
    cout << "sizeof(anotherIntArray) is " << sizeof(anotherIntArray) << endl;

    // Now, pass each array to the printArraySize() call... see what happens!
	printArraySize(intArray);
	printArraySize(anotherIntArray);

    // Now, print some more info on other types
    cout << "sizeof(int) is " << sizeof(int) << endl;
    cout << "sizeof(long) is " << sizeof(long) << endl;
    cout << "sizeof(long long) is " << sizeof(long long) << endl;
    cout << "sizeof(double) is " << sizeof(double) << endl;
    cout << "sizeof(string) is " << sizeof(string) << endl;
}