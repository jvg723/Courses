//
// CS2024 -- Stream Demo #1 (Lecture 22)
//
// Demonstrate Bad Input when reading from cin
//

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  int x;

  // Go into a loop where we'll ask the user to keep entering integers
  while(true) {
    cout << "Enter a number (Enter -1 to quit): ";

    // Read integer
    cin >> x;

    // If -1 was entered, break out of loop
    if (x == -1)
      break;

    // Let the user know what they entered
    cout << "You entered: " << x << endl;
  }
}
