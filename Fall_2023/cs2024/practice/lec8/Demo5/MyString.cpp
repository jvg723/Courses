/*
 * CS2024:  Lecture 8, Demo #5
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

// Standard constructor, makes our string a null-terminated,
// 0 length string
MyString::MyString()
{
  // Make sure that our storage pointer points to the beginning
  // of our statically allocated space
  storagePtr = &initialStorage[0];

  // Note that we have 32 bytes of initial storage
  allocatedSpace = 32;

  // Our string should start out empty, so it's length is 0
  stringLength = 0;

  // Our string should start out empty, so it's initially
  // an empty C-style string (only character is a null
  // terminator
  initialStorage[0] = '\0';
}


// Overloaded constructor... take a C++ string as an initial value
MyString::MyString(string initValue)
{
    // Make sure that our storage pointer points to the beginning
  // of our statically allocated space
  storagePtr = &initialStorage[0];

  // Note that we have 32 bytes of initial storage
  allocatedSpace = 32;

  // Our string should start out empty, so it's length is 0
  stringLength = 0;

  // Our string should start out empty, so it's initially
  // an empty C-style string (only character is a null
  // terminator
  initialStorage[0] = '\0';
  
  if (growStorage(initValue.length())) 
    {
      strcpy(storagePtr,initValue.c_str());
      stringLength = initValue.length();
    }
}



MyString::~MyString() 
{
  if (allocatedSpace > 32) {
    delete [] storagePtr;
  } 
}


// MakeString returns a C++ style string constructed from
// our internal "C" style string
string MyString::MakeString()
{
  string returnVal = storagePtr;  // You can set a C++ string equal to a C style string
  return returnVal;
}


// readString tells cin to read in a new line of text
// into our string
int MyString::readString()
{
  return readString(allocatedSpace-1);
}

int MyString::readString(int maxSize)
{
  // Make sure we have enough storage for a string of length maxSize
  // Add 1 to make sure we have space for the null terminator 
  if (!growStorage(maxSize+1))
    return 0;
    
  // Read directly into the storage area with getline()
  cin.getline(storagePtr,maxSize);

  // Use a C string library call to get the length of the internal
  // C style string.   This is also the lenght of our string
  stringLength = strlen(storagePtr);
  return stringLength;
}


//
// charAt()
//
char &MyString::charAt(int index)
{
  if (isValidIndex(index)) {
    return storagePtr[index];
  } else {
    throw out_of_range("charAt");
  }
}


// growStorage is a private member function which is used
// to grow the buffer used to store our string when needed.
// We grow the buffer in blocks of 32 bytes to minimize the 
// amount of memory allocations we need to do.
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
  
  // fail if new storage allocation fails without
  // touching the existing contents of our string
  if (!newStoragePtr)
    return false;
    
  // copy the contents of the old string into the new
  strcpy(newStoragePtr,storagePtr);
  
  // delete the old string only if it's pointing at 
  // dynamically allocated memory.
  if (allocatedSpace != 32)
    {
      cout << "Calling delete[] from growStorage, allocated space is " << allocatedSpace << endl;
    delete [] storagePtr;
    }
  // Take note of the new size of our allocated space
  allocatedSpace = spaceNeeded;
  
  // store the pointer to the new storage in our class
  storagePtr = newStoragePtr;
  
  return true;
}

