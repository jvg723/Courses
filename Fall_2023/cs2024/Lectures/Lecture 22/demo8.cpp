//
// CS2024 Lecture #22, Demo 8
//
// width and setw
#include <iostream>
#include <iomanip>

using namespace std;

int main (int argc, char * const argv[]) 
{
	// Demonstrate how setwidth works!
	int curWidth = cout.width();

	cout << "curWidth is " << curWidth << endl;
	
	int integers[] = { 15, 335, 7243, 65355,4444993, 12345678};

	// This will apply to the NEXT thing printed out (the setw(7)) so when we go into
	// the for loop below, the first item will have the effects of the setw(7) but the
	// rest will not
	cout << setw(7);
	
	for (int i=0; i<6; i++)
	{
	  //cout << integers[i] << endl;
	  // Use the line below to set the width to 7 for each item printed out in the loop
	   cout << setw(7) << integers[i] << endl;
	}
	
	// Restore original width
	cout.width(curWidth);
}
