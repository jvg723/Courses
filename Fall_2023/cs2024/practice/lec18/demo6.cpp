//
// CS2024 Lecture #18, Demo 6
//
// STL Algorithms: fill
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (int argc, char * const argv[])
{
    vector<char> charvector(10); // Declare a new vector of chars
    char *charptr = new char[10];

    // Use the "fill" algorithm to fill both the char vector 
	// and char pointer with letters
    fill(charvector.begin(),charvector.end(),'Z');
    fill(charptr,charptr+10,'S');

    for (int i=0; i<10; i++)
    {
        cout << "charvector["<<i<<"] contains: " << charvector[i] << endl;
		cout << "charptr["<<i<<"] contains: " << charptr[i] << endl;
    }

    return 0;
}