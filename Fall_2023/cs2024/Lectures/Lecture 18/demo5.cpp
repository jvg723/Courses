//
// CS2024 Lecture #18, Demo 5
//
// dynamic_cast<>
//

#include <iostream>
using namespace std;

// Here's an arbitrary base class
class Base
{
public:
	Base()
	{
		cout << "In Base constructor" << endl;
	}
	
	virtual void someBaseFunction()
	{
	}

};

// Here's an arbitrary derived class D1
class D1 : public Base
{
public:
	D1()
	{
		cout << "In D1 constructor" << endl;
		mPrivateData = 33;
	}
	
	void someD1MemberFunction()
	{
		cout << "Greetings from D1, private data is: " << mPrivateData << endl;
	}
private:
	int mPrivateData;
};


// Here's another arbitrary derived class D2
class D2 : public Base
	{
	public:
		D2()
		{
			cout << "In D2 constructor" << endl;
		}
		
		void someD2MemberFunction()
		{
			cout << "Greetings from D2" << endl;
		}
	};

// Here's some function that can use dynamic casting
void someFunction(Base *bptr)
{
  //D1 *d1Ptr = (D1 *) bptr;  // The old, unsafe way to do it
  D1 *d1Ptr = dynamic_cast<D1 *>(bptr);
    
  //D2 *d2Ptr = dynamic_cast<D2 *>(bptr);
  cout << "d1Ptr is " << (long long) d1Ptr << endl;
  if (d1Ptr)
    	d1Ptr->someD1MemberFunction();
	//	d2Ptr->someD2MemberFunction();
}


int main (int argc, char * const argv[]) 
{
	// Allocate an instance of the D2 derived class and pass to 
	// someFunction.   
    D1 *d1Ptr = new D1();
    //D2 *d2Ptr = new D2();
	
	someFunction(d1Ptr);
	
	// Did we make it out of someFunction?
    cout << "Program ending!\n";
    return 0;
}
