//
// CS2024 -- Lecture #16
//
// Demo #4 -- Passing Lambdas as Parameter
// Introduce capturing local variable
//

#include <iostream>

using namespace std;

// The CallMe() function takes a lambda
// as an argument but no longer requires a second
// argument.   The lambda is using a captured local
// variable to calculate its return value
template<typename T>
void CallMe(T fn)
{
  // Call the function passed in in the variable "f" and
  // store the result in newValue;
  int newValue = fn();
  cout << "newValue is: " << newValue << endl;
}

int main(int argc, char *argv[])
{	
  // Simply call "CallMe" by passing a lambda that doubles
  // the local variable myX.  No need to pass an arg separately
  int myX = 300;
  CallMe([myX]()->int{ return myX*2; });
}

