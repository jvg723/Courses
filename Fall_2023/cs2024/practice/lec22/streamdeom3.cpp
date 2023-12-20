//
// CS2024 -- Stream Demo #1 (Lecture 22)
//
// Detecting bad input and doing something about it
//

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int x;

    // Go into loop where we'll ask the user to keep entering integers
    while(true)
    {
        cout << "Enter a number (Enter -1 to quit): ";

        // Read integer
        cin >> x;

        // Check the fail bit to see if bad input was detected
        if (cin.fail()){
            // Bad input! Let the user know
            cout << "BAD input, try again..." << endl;

            // Clear error state from stream so we can manipulate it encourted
            cin.clear();

            // Ignore up to 80 characters or unitl a newline is encoutered
            cin.ignore(80,'\n');

           // When we go back to the top of the loop, the user will be prompted for more input        
        } else {
           // No error on input, check for -1 and break out of loop if encountered
           if (x == -1)
            break;
        // Let the user know what they entered
        cout << "You entered: " << x << endl;
        }
    }
}