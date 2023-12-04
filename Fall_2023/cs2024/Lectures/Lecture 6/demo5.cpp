//
// CS2024 -- Lecture #9
//
// Demo #5 -- Passing Arguments by Pointer
//

#include <iostream>
using namespace std;

// setToZero() takes a pointer to an integer as its argument
// and stores 0 in the memory pointed at by the argument passed in
void setToZero(int *intPtr)
{
  *intPtr = 0;	
}


int main(int argc, char *argv[])
{	
  int x=5;	// A regular integer local variable
  int *iPtr = NULL;
	
  iPtr = new int();

  if (iPtr == NULL) {
    cout << "Could not allocate memory" << endl;
    return -1;
  }

  setToZero(iPtr);  // Passing a dynamically allocated pointer
  setToZero(&x);    // Passing a pointer to a local variable
  cout << "x = " << x << " and *iPtr = " << *iPtr << endl;
	
  delete iPtr;
}
