//
// CS2024 -- Lecture #16
//
// Demo #5 -- Passing Lambdas as Parameter
//

#include <iostream>
#include <functional>
using namespace std;

// The CallMe() function takes a function pointer
// as an argument as well as an argument to *pass*
// to the function pointed at by f.
template<typename T>
void CallMe(T fn)
{
    // Call the function passed in in the variable "f" and
    // store the result in newValue;
    fn();
}

// DANGEROUS FUNCTION!   Capturing a local variable (x) by reference
// but having x go out of scope before the lambda is ever called!
std::function<void()> someFunction()
{
    int x = 5;
    return [&x](){ cout << "x is " << x << endl; };
}

int main(int argc, char * argv[])
{
    // Simply call "CallMe" by passing a lambda that doubles
    // the local variable myX.  No need to pass an arg separately
    // It captures the local variable myX BY REFERENCE and modifies
    // it directly.   No longer a need to return a value
    int myX = 300;
    CallMe([&myX](){ myX*=2; });

    cout << "myX is " << myX << endl;

    // Call dangerous function!   This likely won't crash, but I doubt
    // we're going to get 5 printed out!
    auto lambda = someFunction();
    CallMe(lambda);
}