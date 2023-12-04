//
// CS2024 Lecture #22, Demo #3
//
// Bitwise Example
//

#include <iostream>
using namespace std;

#define kShiftKey 0x01    // Hexadecimal for 00000001
#define kControlKey 0x02  // Hexadecimal for 00000010
#define kOptionKey 0x04   // Hexadecimal for 00000100
#define kAltKey 0x08      // Hexadecimal for 00001000

// Routine to check if the the Shift Key is pressed
// (if the corresponding bit is set)
bool isShiftPressed(int keyboardModifiers)
{
	if (keyboardModifiers & kShiftKey)
		return true;
	else return false;
}

// Routine to check if the the Control Key is pressed
// (if the corresponding bit is set)
bool isControlPressed(int keyboardModifiers)
{
	if (keyboardModifiers & kControlKey)
		return true;
	else return false;
}

// Routine to check if the the Option Key is pressed
// (if the corresponding bit is set)
bool isOptionPressed(int keyboardModifiers)
{
	if (keyboardModifiers & kOptionKey)
		return true;
	else return false;
}


// Routine to check if the the Alt Key is pressed
// (if the corresponding bit is set)
bool isAltPressed(int keyboardModifiers)
{
	return (keyboardModifiers & kAltKey);
//	if (keyboardModifiers & kAltKey)
//		return true;
//	else return false;
}

// Test it out!
int main (int argc, char * const argv[]) 
{

	// First, we "manufacture" a keyboard state by using...
	// what else... bitwise operators!
	int keyboardState = kShiftKey | kControlKey;
	
	cout << "Keyboard state is: " << keyboardState << endl << endl;
	
        if (isShiftPressed(keyboardState))
		cout << "The SHIFT key is being pressed! " << endl;
	
	if (isOptionPressed(keyboardState))
		cout << "The OPTION key is being pressed! " << endl;
	
	if (isAltPressed(keyboardState))
		cout << "The ALT key is being pressed! " << endl;
	
	if (isControlPressed(keyboardState))
		cout << "The CONTROL key is being pressed! " << endl;
	
    return 0;
}
