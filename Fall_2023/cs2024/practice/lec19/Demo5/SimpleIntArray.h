//
// CS2024 -- Lecture #19, Demo 3
//
// SimpleIntArray.h
//

#include <iostream>

class SimpleIntArray
{
 public:
  SimpleIntArray();
  explicit SimpleIntArray(int size);
  SimpleIntArray(SimpleIntArray&);

  // Declare a move constructor. 
  SimpleIntArray(SimpleIntArray&&) noexcept;
  ~SimpleIntArray();
  int &operator[](int index);
  SimpleIntArray &operator=(SimpleIntArray &);
  
  // Declare an overloaded assignment operator that takes a r-value reference
  // We'll define it in the .cpp file
  SimpleIntArray &operator=(SimpleIntArray &&) noexcept;
  int getSize() { return arraySize; }
  
 private:
  int arraySize;
  int *storagePtr;
};

// Overloaded operator<< allows us to use a SimpleIntArray with cout and <<
inline std::ostream &operator<<(std::ostream &os, SimpleIntArray &sia)
{
	os << "[";
	int size = sia.getSize();
	for (int i=0; i<size; i++) 
	{
		os << sia[i];
		if (i != size-1)
			os << ",";
	}
	
	os << "]";
	return os;
}