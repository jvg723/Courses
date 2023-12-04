//
// CS2024 -- Lecture #19, Demo 3
//
// SimpleIntArray.cpp
//

#include <iostream>

#include "SimpleIntArray.h"

// Default constructor doesn't allocate any space for elements in the array
SimpleIntArray::SimpleIntArray()
{
  std::cout << "In SimpleIntArray default constructor" << std::endl;
  arraySize = 0;
  storagePtr = nullptr;
}

// Overloaded constructor allows us to specify the amount of storage space for
// the SimpleIntArray being created.  We delegate to the default constructor 
// so we don't have to duplicate code of initializing arraySize to 0 and 
// storagePtr to nullptr
SimpleIntArray::SimpleIntArray(int size):SimpleIntArray()
{
  std::cout << "In SimpleIntArray constructor(int)" << std::endl;
  storagePtr = new(std::nothrow) int[size];
  
  if (storagePtr) 
  	arraySize = size;
}

// Copy constructor allows us to properly copy dynamically allocated memory
// from the source SimpleIntArray to the one being created
SimpleIntArray::SimpleIntArray(SimpleIntArray& copyFrom)
{
  std::cout << "In SimpleIntArray copy constructor" << std::endl;
  storagePtr = new(std::nothrow) int[copyFrom.arraySize];
  if (storagePtr) {
  	arraySize = copyFrom.arraySize;
  	for (int i=0; i<arraySize; i++)
  		storagePtr[i] = copyFrom[i];
  }
  else
    arraySize = 0;
}

// Destructor frees dynamically allocated memory
SimpleIntArray::~SimpleIntArray()
{
  std::cout << "In SimpleArray destructor" << std::endl;
  if (storagePtr) {
    std::cout << "  freeing dynamic memory, size of array was " << arraySize << std::endl;
  	delete [] storagePtr;
  }
}

// Overloaded assignment operator allows us to get access to a particular
// element of the array, will throw an exception if the index is out of range
int &SimpleIntArray::operator[](int index)
{
	if (storagePtr && arraySize && (index >= 0) && (index < arraySize))
	{
		return storagePtr[index];
	}
	
	throw std::out_of_range("bad index encountered in SimpleIntArray");
}


// Overloaded assignment operator allows us to properly copy dynamically allocated
// memory from the source SimpleIntArray to the destination
SimpleIntArray &SimpleIntArray::operator=(SimpleIntArray &copyFrom)
{
  std::cout << "In SimpleIntArray operator= " << std::endl;
  storagePtr = new(std::nothrow) int[copyFrom.arraySize];
  if (storagePtr) {
  	arraySize = copyFrom.arraySize;
  	for (int i=0; i<arraySize; i++)
  		storagePtr[i] = copyFrom[i];
  }
  else
    arraySize = 0;
    
  return *this;
}
