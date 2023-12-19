//
// CS2024 -- Lecture #19, Demo 2
//
// SimpleIntArray.cpp
//

#include <iostream>

#include "SimpleIntArray.h"

SimpleIntArray::SimpleIntArray()
{
    arraySize = 0;
    storagePtr = nullptr;
}

// Overloaded constructor takes a size to allocate space in our array
SimpleIntArray::SimpleIntArray(int size):SimpleIntArray()
{
    // Use std:nothrow so that storagePtr will be nulptr if allocation fails
    storagePtr = new(std::nothrow) int[size];

    // Only update array size if allocation succded
    if (storagePtr)
        arraySize = size;
}

// Destructor cleans up dynamically allocated memory
SimpleIntArray::~SimpleIntArray()
{
    if (storagePtr)
        delete [] storagePtr;
}

// Simple overloaded array index operator, will throw exception if array index is out of range
int &SimpleIntArray::operator[](int index)
{
    if (storagePtr && arraySize && (index >= 0) && (index < arraySize))
    {
        return storagePtr[index];
    }

    throw std::out_of_range("bag index encountered in SimpleIntArry");
}