//
// CS2024 Lecture #16, Demo 4
//
// MyArray
//

#include <stdexcept>

// Here's the MyArray template class
template <class T>
class MyArray
{
 public:
  MyArray(int size);
  ~MyArray();
  T &operator[](int i);

 private:
  T *arrayStore;
  int arraySize;
};

// Constructor takes a size of the array as a parameter and allocates 
// enough space
template <class T>
MyArray<T>::MyArray(int size)
{
  arraySize = size;
  arrayStore = new T[size];
}

// The destructor cleans up our dynamically allocated memory
template <class T>
MyArray<T>::~MyArray()
{
  delete [] arrayStore;
}


// Overload array index operator
template <class T>
T& MyArray<T>::operator[](int i) 
{
  if ((i < 0) || (i >= arraySize)) {
    // throw an exception
    throw out_of_range("MyArray index is out of range");
  }

  return(arrayStore[i]);
}
