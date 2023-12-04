//
// CS2024 -- Lecture #24
//
// Demo #4:  make_shared
//

#include <iostream>

class MyClass 
{
public:
	MyClass(int arg) {  mArg = arg; }
	
	// Uncomment lines below to see what's going on!
	// MyClass() = default;
	//MyClass(MyClass&) {
	//	std::cout << "you made a copy with copy constructor!" << std::endl;
	//	mArg = source.mArg;
	//}
	
	//MyClass(MyClass &&source) {
	//	std::cout << "you made a copy with move copy constructor!" << std::endl;
	//	mArg = source.mArg;
	//}
	
	void printArg() { std::cout << "mArg is: " << mArg << std::endl; }
	
private:
	int mArg;
};


int main(int argc,char *argv[])
{
	std::shared_ptr<MyClass> p = std::make_shared<MyClass>(10);
	
	// Same as
	std::shared_ptr<MyClass> q(new MyClass(11));
	
	
	// But not this (even though it looks like it works)
	std::shared_ptr<MyClass> r = std::make_shared<MyClass>(MyClass(50));
	
	p->printArg();
	q->printArg();
	r->printArg();
}


