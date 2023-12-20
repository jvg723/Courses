//
// CS2024 -- Lecture #22, Demo 5
//
// get with arguments and getline
// similar to demo code at Figure 13.3 in Deitel/Deitel
//

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    const int SIZE{16}; // We're setting SIZE low so we can see what happens when we put in too much
    char buffer1[SIZE];
    char buffer2[SIZE];
    char c;

    // Use get with one argument
    cout << "Enter a character: ";
    cin.get(c);

    cout << "You entered character: " << c << " with integer value: " << (int)c << endl;

    // use cin to input characters into buffer1
    cout << "Enter a string: " << endl;

    // REMEMBER:  when using cin and >>, stops on whitespace
    cin >> buffer1;

    // Display buffer
    cout << "string aread in was: " << buffer1 << endl;

    // Now repeat with get
    cout << "enter another string: " << endl;
    // stops on '\n'.  Remember to use ignore to get the newline from the single string entry
    // out of the input buffer.

    cin.ignore();

    // And what happens if there's and emoji close to the last allowable character?
    cin.get(buffer2,SIZE);

    cout << "The string entered was: " << buffer2 << endl;

    // What's the next character in the buffer?
    // get() leaves the delimiter in the buffer
    cin.get(c);
    cout << "Next character is: " << c << ", with integer value: " << (int)c << endl;
}