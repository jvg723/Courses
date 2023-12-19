//
// CS2024 -- Lecture #19, Demo 3
//
// SimpleIntArray.cpp
//

#include <iostream>

#include "SimpleIntArray.h"

SimpleIntArray::SimpleIntArray()
{
  std::cout << "In SimpleIntArray default constructor" << std::endl;
  arraySize = 0;
  storagePtr = nullptr;
}

SimpleIntArray::SimpleIntArray(int size):SimpleIntArray()
{
  std::cout << "In SimpleIntArray constructor(int)" << std::endl;
  storagePtr = new(std::nothrow) int[size];
  
  if (storagePtr) 
  	arraySize = size;
}

// Copy constructor allows us to properly copy dynamically allocated memory
// from the source SimpleIntArray to the one being created
SimpleIntArray::SimpleIntArray(const SimpleIntArray& copyFrom)
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

SimpleIntArray::SimpleIntArray(SimpleIntArray&& moveFrom) noexcept
{
  std::cout << "In simpleIntArray move constructor" << std::endl;
  // Take a meory pointer from moveFrom and store it locally
  storagePtr = moveFrom.storagePtr;
  arraySize = moveFrom.arraySize;

  // Then store nullptr in the source instances's storagePtr so its
	// destructor doesn't try to free it
  moveFrom.arraySize = 0;
  moveFrom.storagePtr = nullptr;
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
int &SimpleIntArray::operator[](int index) const
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

SimpleIntArray &SimpleIntArray::operator=(SimpleIntArray&& moveFrom) noexcept
{
    std::cout << "In simpleIntArray move assignment operator" << std::endl;
    // Take a meory pointer from moveFrom and store it locally
    storagePtr = moveFrom.storagePtr;
    arraySize = moveFrom.arraySize;

    // Then store nullptr in the source instances's storagePtr so its
	  // destructor doesn't try to free it
    moveFrom.arraySize = 0;
    moveFrom.storagePtr = nullptr;

    return *this;
}
