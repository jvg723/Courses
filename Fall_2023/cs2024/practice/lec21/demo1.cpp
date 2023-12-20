//
// CS2024 -- Lecture #21, Demo #1
//
// Avoiding Copies?
//
#include <iostream>
#include <map>

// Here's SomeClass, a simple class that tells us what constructors are being called,
// as well as tells us when the destructor and overloaded assignment operator is called.
class SomeClass
{
    public:
        SomeClass() { std::cout << "SomeClass default constructor" << std::endl;}
        SomeClass(int i) { std::cout << "SomeClass int constructor (" << i << ")" << std::endl; someMemberVar = i;}
        SomeClass(const SomeClass &copyFrom) { std::cout << "SomeClass COPY constructor: " << someMemberVar << std::endl; someMemberVar = copyFrom.someMemberVar;}
        ~SomeClass() { std::cout << "In SomeClass DESTRUCTOR" << std::endl;}
        SomeClass &operator=(const SomeClass &assignFrom)
        {
            std::cout << "SomeClass ASSIGNMENT opertor" << std::endl;
            someMemberVar = assignFrom.someMemberVar;
            return *this;
        }
        int someMemberVar;
};

// Here's an overloaded stream insertion operator so we can use SomeClass with cout
std::ostream &operator<<(std::ostream& os, SomeClass &someClass)
{
    os << "SomeClass(" << someClass.someMemberVar << ")";
    return os;
}

int main(int argc, char *argv[])
{
    std::map<int,SomeClass> myMap;

    // Put a few entries into the map
    SomeClass sc1(5);
    SomeClass sc2(10);

    myMap[1] = sc1;
    myMap[2] = sc2;

    // Print out contents of map
    for (std::map<int,SomeClass>::iterator p = myMap.begin(); p != myMap.end(); p++)
    {
        std::cout << "map " << p->first << " = " << p->second << std::endl;
    }
}