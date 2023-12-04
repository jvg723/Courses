//
// CS2024 -- Lecture #7
//
// Demo #5 -- Vectors
//

#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char * argv[]) {
  // Declare a vector of type int
  vector<int> intVector;
	
  // Load it up with some primes
  intVector.push_back(2);
  intVector.push_back(3);
  intVector.push_back(5);
  intVector.push_back(7);
  intVector.push_back(11);
	
  // try the size() member function
  cout << "The vector now has " << intVector.size() << " elements." << endl;
	
  // look at all the entries using the [] method
  // Note that this does not remove anything from the vector
  for (int i=0; i<intVector.size(); i++)
  {
    cout << "Element #" << i << " = " << intVector[i] << endl;
  }

  // Remove the last element from vector
  int element = intVector.back();
  intVector.pop_back();

  cout << "We just popped " << element << " out of the vector " << endl;
  cout << "And the size of the vector is now: " << intVector.size() << endl;


  // Now we will try to write an element into the vector 
  // that is out of bounds.  This *might* crash, but either
  // way it is certainly writing memory somewhere it shouldn't be!
  //  intVector.at(1111) = 19;
  intVector[1111] = 19;
}
