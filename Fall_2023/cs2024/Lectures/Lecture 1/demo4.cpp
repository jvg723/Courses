//
// CS 2024 -- Lecture #1
//
// Demo #4: using string variable with getline
//

#include <iostream> 
#include <string>   // Some compilers need you to include this separately

using std::cin;
using std::cout;
using std::endl;
using std::string;  // Some compilers have string definition included from iostream

// Here's our main function
int main (int argc, char * const argv[]) 
{
  string stringVariable;

  cout << "Please enter a string: " << endl;
  getline(cin,stringVariable);  // getline is a GLOBAL function

  cout << "You entered: " << stringVariable << endl;

  return 0;
}
