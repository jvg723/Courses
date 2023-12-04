//
// CS2024 -- Lecture 9
//
// Demo #1:  Pointers with Dynamic Allocation
//

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
  // Declare a new pointer iPtr and allocate space for one integer
  int *iPtr = new int;

  // Make sure allocation succeeded (this is the old way to check
  // for successful allocation; we'll cover the more modern way
  // later in the course)
  if (iPtr == NULL) 
  {
    cout << "Could not allocate pointer, bye!";
    return -1;
  }

  *iPtr = 5;   // Will actually write data into memory
  cout << "iPtr is " << iPtr << " and *iPtr is " << *iPtr << endl;
  
  delete iPtr; // This is how you dispose of a pointer
  return 0;
}
