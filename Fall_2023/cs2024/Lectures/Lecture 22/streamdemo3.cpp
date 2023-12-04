//
// CS2024 -- Stream Demo #3 (Lecture #22)
//
// Detecting bad input and doing something about it
//

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  int x;

  // Enter a loop where we will keep asking the user to input integers
  while(true) {
    cout << "Enter a number (Enter -1 to quit): ";
    cin >> x;

    // Check the fail bit to see if bad input was detected
    if (cin.fail()) {
      // Bad input!  Let the user know
      cout << "BAD input, try again... " << endl;

      // Clear error state from stream so we can manipulate it
      cin.clear();

      // Ignore up to 80 characters or until a newline is encountered
      cin.ignore(80,'\n');

      // When we go back to the top of the loop, the user will be prompted for more input
    } else {
      // No error on input, check for -1 and break out of loop if encountered
      if (x == -1)
	break;

      // Show the user what they entered
      cout << "You entered: " << x << endl;
    }
  }
}
