//
// CS2024 Lecture #12, Demo 4
//
// Stack unwinding
//

#include <iostream>

using namespace std;  //introduces namespace std

// Create a Simple Class that has a destructor
// with a debugging message
class SimpleClass
{
    public:
        SimpleClass(int x):mX(x) {}
        ~SimpleClass(){
            cout << "Destroying SimpleClass(" << mX << ")" << endl;
        }
    private:
        int mX;
};

// Here's a function that throws and exception
void func1()
{
    SimpleClass sc(3);

    // Throw an arbitrary exceptoin so we can see if sc's destructor is called
    throw 3.14;
    cout << "This will never be printed" << endl;
}

// This function will call func1() and can catch
// a "double" type exception
void func2() 
{
  SimpleClass sc(2);
  try {
    func1();
  }
   catch(double d) {
    cout << "Caught double exception" << endl;
  }
}

// Kick it all off!
int main(int argc,char *argv[]) 
{
  SimpleClass sc(1);
  try {
  func2();
  } catch (...) {
  }
}