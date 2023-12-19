/*
 * CS2024:  Lecture 9, Demo #5
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

// Copy constructor
MyString::MyString(MyString &aCopy)
{
    stringLength = aCopy.stringLength;
    if (aCopy.allocatedSpace > 32)
    {
        storagePtr = new char [aCopy.allocatedSpace];
        if (!storagePtr)
        {
            // Couldn't allocate space, return an empty string
            allocatedSpace = 32;
            storagePtr = &initialStorage[0];
            *storagePtr = '\0';
            stringLength = 0;
            return;
        }

        // strcpy is a C standard library function for copying c style strings
        strcpy(storagePtr,aCopy.storagePtr);
        allocatedSpace = aCopy.allocatedSpace;
        return;
    }

    strcpy(initialStorage,aCopy.initialStorage);
    allocatedSpace = 32;
    return;
}

MyString::~MyString()
{
    if (allocatedSpace > 32)
    {
        delete [] storagePtr;
    }
}

// Overload =
MyString &MyString::operator=(const MyString &sourceStr)
{
    // Make sure we actually have two pointers
    if (this != &sourceStr)
        setValue(+sourceStr);
    return *this;
}

// Overload ~ to return string length
int MyString::operator~()
{
    return stringLength;
}

// Overload + to return a C++ string class instance
string MyString::operator+() const
{
    return MakeString();
}

// overload the [] operator 
char &MyString::operator[](int index) const
{
  return charAt(index);
}

// MakeString returns C++ style string constructed from
// our internal "C" style string
string MyString::MakeString() const
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
char &MyString::charAt(int index) const
{
    if (isValidIndex(index))
    {
        return storagePtr[index];
    } else {
        throw out_of_range("charAT");
    }
}

// setValue would provide a way to assign an exisitn 
// value to our string 
bool MyString::setValue(const string cppString)
{
    int spaceNeeded = cppString.length();

    // make sure we have enough space to hold the new string
    if (spaceNeeded > allocatedSpace)
    {
        if (!growStorage(spaceNeeded+1))
            return false;
    }

    strcpy(storagePtr,cppString.c_str());
    stringLength = spaceNeeded;
    return true;
}

// getAllocatedSpace() simply returns the amount of space
// allocated to our MyString (either the initial 32 bytes or 
// some dynamically allocated amount).   This is needed by
// our operator>> overload to know how much storage exists
// in the MyString we are reading into
int MyString::getAllocatedSpace()
{
    return allocatedSpace;
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