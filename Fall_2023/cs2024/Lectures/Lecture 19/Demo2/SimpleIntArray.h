//
// CS2024 -- Lecture #19, Demo 2
//
// SimpleIntArray.h
//

#include <iostream>

class SimpleIntArray
{
 public:
  SimpleIntArray();
  explicit SimpleIntArray(int size);
  ~SimpleIntArray();
  int &operator[](int index);
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