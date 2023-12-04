//
// CS2024 -- Stream Demo #2 (Lecture #22)
//
// Checking all stream flags after input
//

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  int x;

  // Enter a loop where we keep asking the user to enter integers
  while(true) {
    cout << "Enter a number (Enter -1 to quit): ";
    cin >> x;

    // Check state of stream after input
    cout << "cin state: ";
    if (cin.good()) cout << "GOOD "; else cout << "good ";
    if (cin.bad()) cout << "BAD "; else cout << "bad ";
    if (cin.fail()) cout << "FAIL "; else cout << "fail ";
    if (cin.eof()) cout << "EOF "; else cout << "eof ";
    cout << endl;

    // If user entered -1, break out of loop
    if (x == -1)
      break;

    // Let user know what they entered
    cout << "You entered: " << x << endl;
  }
}
