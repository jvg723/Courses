//
// CS2024 Lecture #15 Demo #4
//
// Same demo as demo #2, but we sort the vector first

#include <iostream>
#include <vector>

using namespace std;  //introduces namespace std

int main()
{
	vector<string> stringVector;	// Declare a new vector
	
	stringVector.insert(stringVector.end(),"This");
	stringVector.insert(stringVector.end(),"is");
	stringVector.insert(stringVector.end(),"a");
	stringVector.insert(stringVector.end(),"test");
	stringVector.insert(stringVector.end(),"of");
	stringVector.insert(stringVector.end(),"the");
	stringVector.insert(stringVector.end(),"emergency");
	stringVector.insert(stringVector.end(),"broadcasting");
	stringVector.insert(stringVector.end(),"system");  
	stringVector.insert(stringVector.end(),"!!!");

	// SORT THE VECTOR!
	sort(stringVector.begin(),stringVector.end());
	
	// Print out vector contents
	cout << "Here comes the initial vector" << endl;
	for (vector<string>::iterator k = stringVector.begin();
		 k < stringVector.end(); ++k)
	{
		cout << "Next Vector Element is: " << *k << endl; 
	}
	
	// Now, show some erase operations
	vector<string>::iterator q = stringVector.begin();
	
	// erase the 6th item  ("the")
	stringVector.erase(q+5);
	
        // Print out the vector again
	cout << endl  << "Here comes the vector after removing the 6th element" << endl;
	for (vector<string>::iterator k = stringVector.begin();
		 k < stringVector.end(); ++k)
	{
		cout << "Next Vector Element is: " << *k << endl; 
	}
	
	// erase the first 5 items
	q = stringVector.begin();
	stringVector.erase(q,q+5);
	
	cout << endl << "Here comes the vector again after removing the first 5 items" << endl;
	for (vector<string>::iterator k = stringVector.begin();
		 k < stringVector.end(); ++k)
	{
		cout << "Next Vector Element is: " << *k << endl; 
	}
	
}

