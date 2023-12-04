//
// CS2024 -- Lecture #24
//
// Demo #1:  default designator
//

#include <iostream>

class MyClass 
{
public:
	MyClass(int arg) {  mArg = arg; }
	
	// Uncomment line below to have compiler generate a "default" constructor
	// MyClass() = default;
	
	void printArg() { std::cout << "mArg is: " << mArg << std::endl; }
	
private:
	int mArg;
};


int main(int argc,char *argv[])
{
	MyClass  myClass1(1);
	
	// Since we've declared one constructor that takes an argument, we no longer
	// have a default constructor for this type of initialization
	MyClass  myClass2;
	
	myClass1.printArg();
	myClass2.printArg();
}


