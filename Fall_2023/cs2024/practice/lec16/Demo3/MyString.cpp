/*
 * MyString.cpp
 *
 * Implementation of the MyString class
 * Version 0.2
 *   --Add constructor which takes string
 *   --Add destructor
 * Version 0.4
 *   --Add various operator overloads
 *   --Add findChar
 * Version 0.5
 *   --Fixed for problems with various compilers
 */



#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#include "MyString.h"

// Standard constructor, makes our string a null-terminated,
// 0 length string
MyString::MyString()
{
  storagePtr = &initialStorage[0];
  allocatedSpace = 20;
  stringLength = 0;
  initialStorage[0] = '\0';
}

// Constructor which allows an initial value to be set
MyString::MyString(string initialValue)
{
  storagePtr = &initialStorage[0];
  allocatedSpace = 20;
  stringLength = 0;
  initialStorage[0] = '\0';
  setValue(initialValue);
}

// Copy Constructor
MyString::MyString(MyString &aCopy)
{
  stringLength = aCopy.stringLength;
  if (aCopy.allocatedSpace > 20)
  {
    storagePtr = new char[aCopy.allocatedSpace];
    if (!storagePtr)
    {
      // Couldn't allocate space, return an empty string
      allocatedSpace = 20;
      storagePtr = &initialStorage[0];
      *storagePtr = '\0';
      stringLength = 0;
      return;
    }
    
    strcpy(storagePtr,aCopy.storagePtr);
    allocatedSpace = aCopy.allocatedSpace;
    return;
  }
  
  strcpy(initialStorage,aCopy.initialStorage);
  allocatedSpace = 20;
  storagePtr = &initialStorage[0];
}
    

// Standard destructor, frees dynamically allocated memory
MyString::~MyString()
{
  if (allocatedSpace > 20)
  {
    cout << "MyString:  Freeing '" << MakeString() << "' " << endl;
    cout << "MyString:  Freeing " << allocatedSpace << " bytes of memory! " << endl;
    delete storagePtr;
  }
}


// Overload =
MyString &MyString::operator=(const MyString &sourceStr)
{  
  // Make sure we actually have two pointers
  if (this != &sourceStr)
    setValue((string)sourceStr);
  return *this; 
}

// Overload ~ to return string length
int MyString::operator~()
{
  return stringLength;
}
  
// Overload (string) cast to return a C++ string class instance
MyString::operator string() const
{
  return MakeString();
}

// Overload [] to give us array like functionality   
char &MyString::operator[](int i) const
{
  return element(i);
}


// MakeString returns a C++ style string constructed from
// our internal "C" style string
string MyString::MakeString() const
{
  string returnVal = storagePtr;
  return returnVal;
}

// MakeInt utilized the C Standard library function "atoi" 
// to convert our string to an integer 
int MyString::MakeInt() const
{
  return( atoi(storagePtr) );
}

// readString tells cin to read in a new line of text
// into our string
int MyString::readString()
{
  return readString(allocatedSpace-1);
}

int MyString::readString(int maxSize)
{
  // Make sure we have enough storage 
  if (!growStorage(maxSize))
    return 0;
    
  cin.getline(storagePtr,maxSize);
  stringLength = strlen(storagePtr);
  return stringLength;
}


//
// MyString::findChar is used to find the first index at which the
// specified character appears.
//
int MyString::findChar(char c,int startPos,int stopPos)
{
  int stopAt = stringLength -1;
  
  if ((stopPos > 0) && (stopPos < stopAt))
    stopAt = stopPos;
  
    
  // Search for the specified character
  for (int k=startPos; k<=stopAt; k++)
    if (storagePtr[k] == c)
      return k;  // Found it!  Return the index to the caller

  // Didn�t find it, return -1;
  return -1;
}

//
// element lets us get at an individual character in our string
//
static char tempStorage;
char &MyString::element(int i) const
{

  if ((i > 0) && (i < stringLength))
    return( storagePtr[i] );
  return tempStorage;
}

// setValue would provide a way to assign an existing 
// value to our string (that is, without reading in from
// standard console)
bool MyString::setValue(string cppString)
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
  if (allocatedSpace != 20)
    delete storagePtr;
  
  // Take note of the new size of our allocated space
  allocatedSpace = spaceNeeded;
  
  // store the pointer to the new storage in our class
  storagePtr = newStoragePtr;
  
  return true;
}

