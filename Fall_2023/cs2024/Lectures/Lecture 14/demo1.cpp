//
// CS2024 -- Lecture #16
//
// Demo #1 -- Function Pointers
//

#include <iostream>

using namespace std;

// The CallMe() function takes a function pointer
// as an argument as well as an argument to *pass*
// to the function pointed at by f.
void CallMe(int (*f)(int), int x)
{
    // Call the function passed in in the variable "f" and
    // store the result in newValue;

    // This is confusing because with function pointers you can
    // call the function either way below
  
    int newValue = f(x);
    //int newValue = (*f)(x);
    cout << "newValue is: " << newValue << endl;
}

// Here's a simple function that takes an integer
// and returns an integer
int doubleIt(int q)
{
	return (q*2);
}


int main(int argc, char *argv[])
{	
	// Simply call "CallMe" by passing a pointer to the doubleIt
	// function and the argument 300.
	int myX = 300;
	CallMe(doubleIt,myX);
}

