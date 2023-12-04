//
// CS2024 -- Lecture #24
//
// Demo #2:  delete designator
//

#include <iostream>

class MyClass 
{
public:
	MyClass(int arg) {  mArg = arg; }
	MyClass() = default;
	
	// Uncomment this line to show the effects of "deleting" the 
	// compiler's default copy constructor
	// MyClass(MyClass&) = delete;
	
	void printArg() { std::cout << "mArg is: " << mArg << std::endl; }
	
private:
	int mArg;
};


int main(int argc,char *argv[])
{
	MyClass  myClass1(1);
	
	// Utilize a copy constructor for the myClass2 instance
	// Of course, there must *be* a copy constructor for this to work!
	MyClass  myClass2(myClass1);
	
	myClass1.printArg();
	myClass2.printArg();
}


