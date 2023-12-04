//
// CS 2024 -- Lecture #1
//
// Demo #3: using string variable with cin
//

#include <iostream>

// In order to use the string type, some compilers may require you to
// include the string header separately.  Others will be fine if you
// just include iostream
#include <string>

// Make use of the using statement
using std::cin;
using std::cout;
using std::endl;
using std::string;

// Could also have done this:
// using namespace std;

// Here's our main function
int main (int argc, char * const argv[]) 
{
  string stringVariable;

  cout << "Please enter a string: " << endl;
  cin >> stringVariable;

  cout << "You entered: " << stringVariable << endl;

  return 0;
}
