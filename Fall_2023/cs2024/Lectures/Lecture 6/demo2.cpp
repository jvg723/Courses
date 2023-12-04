//
// CS2024 -- Lecture 9
//
// Demo #2:  Pointers to existing variables
//

#include <iostream>

using namespace std;

//
// A slight variation on Demo #1
//

int main(int argc, char *argv[]) 
{
  int *iPtr = NULL;
  int anotherVariable = 10;

  iPtr = &anotherVariable;  // use & to get address of variable
  
  cout << "iPtr is " << iPtr << " and *iPtr is " << *iPtr << endl;

  // Now, dynamically allocate memory for iPtr
  iPtr = new int;

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
