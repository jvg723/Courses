//
// CS2024 -- Lecture #19, Demo 6
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
  
  // Declare a move constructor.  We'll define it in the .cpp file
  SimpleIntArray(SimpleIntArray&&) noexcept;
  ~SimpleIntArray();
  int &operator[](int index);
  SimpleIntArray &operator=(SimpleIntArray &);
  SimpleIntArray &operator=(SimpleIntArray &&) noexcept;
  int getSize() { return arraySize; }
  
 private:
  int arraySize;
  int *storagePtr;
};

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