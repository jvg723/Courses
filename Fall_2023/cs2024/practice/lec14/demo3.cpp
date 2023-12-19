//
// CS2024 -- Lecture #16
//
// Demo #3 -- Passing Lambdas as Parameter
//

#include <iostream>
#include <functional>
using namespace std;

// The CallMe() function takes a function pointer
// as an argument as well as an argument to *pass*
// to the function pointed at by f.
template<typename T>
void CallMe(T fn, int x)
{
    // Call the function passed in in the variable "f" and
    // store the result in newValue;
  
    // NOTE:  This will only work if the T parameter is an actual callable
    //        function (pointer, lambda, etc.).  If not, it will be a syntax error

    int newValue = fn(x);
    cout << "CallMe-newValue is: " << newValue << endl;
}

void AltCallMe(std::function<int(int)> f, int x)
{
    // Call the function passed in in the variable "f" and                         
    // store the result in newValue;
    int newValue = f(x);
    cout << "AltCallMe-newValue is: " << newValue << endl; 
}

void OldCallMe(int (*f)(int), int x)
{
    // Call the function passed in in the variable "f" and                         
    // store the result in newValue;
    int newValue = (*f)(x);
    cout << "OldCallMe-newValue is: " << newValue << endl; 
}

int main(int argc, char * argv[])
{
    // Simply call "CallMe" by passing a pointer to the doubleIt
    // function and the argument 300.
    int myX = 300;
    CallMe([](int x)->   int{ return x*2; },myX);
    AltCallMe([](int x)->int{ return x*2; },myX);
    OldCallMe([](int x)->int{ return x*2; },myX);
}