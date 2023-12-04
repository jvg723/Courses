//
// CS2024 -- Lecture #21, Demo #4
//
// More unintended copies
//
#include <iostream>
#include <map>

// Here's SomeClass, a simple class that tells us what constructors are being called,
// as well as tells us when the destructor and overloaded assignment operator is called.
class SomeClass
{
public:
  SomeClass() { std::cout << "SomeClass default constructor" << std::endl; }
  SomeClass(int i) { std::cout << "SomeClass int constructor (" << i << ")" << std::endl; someMemberVar = i;}
  SomeClass(const SomeClass &copyFrom) {std::cout << "SomeClass COPY constructor: " << copyFrom.someMemberVar << std::endl; 
  	someMemberVar = copyFrom.someMemberVar;}
  ~SomeClass() { std::cout << "In SomeClass DESTRUCTOR" << std::endl; }
  SomeClass &operator=(const SomeClass &assignFrom) 
  {  std::cout << "SomeClass ASSIGNMENT operator" << std::endl; 
    someMemberVar = assignFrom.someMemberVar;
    return *this;
  }
  int someMemberVar;
};

// Here's an overloaded stream insertion operator so we can use SomeClass with cout
std::ostream &operator<<(std::ostream& os,SomeClass &someClass)
{
  os << "SomeClass(" << someClass.someMemberVar << ")";
  return os;
}


int main(int argc,char *argv[])
{
  std::map<int,SomeClass> myMap;

  // Put a few entries into the Map
  // Use emplace to construct the item "in place (in the map)"
  myMap.emplace(1,5);
  myMap.emplace(2,10);

  // Let's use a range-based for loop to iterate through our map!
  for (std::pair<int,SomeClass> q : myMap)
    {
      std::cout << "map " << q.first << " = " << q.second << std::endl;
    }
}

