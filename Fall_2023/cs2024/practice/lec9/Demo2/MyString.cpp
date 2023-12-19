/*
 * CS2024:  Lecture 9, Demo #2
 *
 * MyString.cpp
 *
 * Implementation of the MyString class
 *   -- Initial version
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstring>
using namespace std;

#include "MyString.h"

// A better way to handle multiple constructors, at least until C++-11
void MyString::baseInitilization()
{
    // Make sure that our storage pointer points to the begining 
    // of our statically allocated space
    storagePtr = &initialStorage[0];

    // Note we have 32 bytes of initial storage
    allocatedSpace = 32;

    // Our string length should start out empty, so its length is 0
    stringLength = 0;

    // Our string should start out empty, so its initially
    // an empty C-style string (only character is a null terminator)
    initialStorage[0] = '\0';
}

// Standard constructor, makes our string a null-terminated,
// 0 length string
MyString::MyString()
{
    baseInitilization();
}

// Overloaded constructor... take a C++ string as an initial value
MyString::MyString(string initValue)
{
    baseInitilization();
    if (growStorage(initValue.length()))
    {
        strcpy(storagePtr,initValue.c_str());
        stringLength = initValue.length();
    }
}

MyString::~MyString()
{
    if (allocatedSpace > 32)
    {
        delete [] storagePtr;
    }
}

// Overload ~ to return string length
int MyString::operator~()
{
    return stringLength;
}

// Overload + to return a C++ string class instance
string MyString::operator+()
{
    return MakeString();
}

// MakeString returns C++ style string constructed from
// our internal "C" style string
string MyString::MakeString()
{
    string returnVal = storagePtr; // You can set a C++ string equal to a C style string
    return returnVal;
}

// readString tell cin to read in a new line of text
// into our string
int MyString::readString()
{
    return readString(allocatedSpace-1);
}

int MyString::readString(int maxSize)
{
    // Make sure we have enough storage for a string of length maxSize
    // Add 1 to make sure we have space for null terminator
    if (!growStorage(maxSize+1))
        return 0;

    // Read directly into the storage area with getline()
    cin.getline(storagePtr,maxSize);

    // Use C string library calll to get the length of the internal
    // C style string. This is also the length of our string
    stringLength = strlen(storagePtr);
    return stringLength;
}

//
// charAt()
//
char &MyString::charAt(int index)
{
    if (isValidIndex(index))
    {
        return storagePtr[index];
    } else {
        throw out_of_range("charAT");
    }
}

// growStorage is a private member function which is used 
// to grow the buffer used to store our string when needed.
// We grow the buffer in block of 32 bytes to minimize the 
// amout of memory allocations we need to do.
bool MyString::growStorage(int spaceNeeded)
{
    // Make sure it really needs to grow
    if (spaceNeeded < allocatedSpace)
        return true;

    // grow in chunks of 32 bytes
    int padding = spaceNeeded % 32;
    spaceNeeded += (32 - padding);

    // allocate new storage
    char *newStoragePtr = new char[spaceNeeded];

    // fail in new storage alocation fails without
    // toughing th eexisitng contents of our string
    if (!newStoragePtr)
        return false;

    // copy the contents of the old string into the new
    strcpy(newStoragePtr,storagePtr);

    // delete the old string only if its pointing at 
    // dynamically allocated memory.
    if (allocatedSpace != 32)
    {
        cout << "Calling delete [] from growStorage, allocated space is " << allocatedSpace << endl;
        delete [] storagePtr;
    }
    // Take note of the new size of our allocated space
    allocatedSpace = spaceNeeded;

    // store the pointer to the new storage in our class
    storagePtr = newStoragePtr;

    return true;
}