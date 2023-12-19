//
// CS2024 Lecture #18, Demo 7
//
// STL Algorithms: generate
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// nextValue keeps a static variable that acts
// as a counter, always returns the current value
// and then increments that value by 1
int __nextValue()
{
    static int number = 0;
    return number++;
}

int main (int argc, char * const argv[])
{
    vector<int> intVector(10); // Declare new vector of chars

    // Use the "generate" algorithm to fill the 
	// vector with generated values
    generate(intVector.begin(),intVector.end(),__nextValue);

    // Print out the vector after having used generate()
	for (int i=0; i<10; i++)
	{
		cout << "intVector["<<i<<"] contains: " << intVector[i] << endl;
	}
	
	
    return 0;
}