//
// CS2024 Lecture #15, Demo #2
//
// vector/stack
//

#include <iostream>
#include <vector>

using namespace std;  //introduces namespace std

int main()
{
    vector<string> stringVector;    // Declare a new vector
    stringVector.push_back("This");
    stringVector.push_back("is");
    stringVector.push_back("a");
    stringVector.push_back("test");

    // First forward
    cout << "Here comes the vector in forward order" << endl;
    for (vector<string>::iterator p = stringVector.begin(); p < stringVector.end(); p++)
    {
        cout << "Next Vector Element is: " << *p << endl;
    }

    // Now backward
    cout << endl << "Here comes the vector in backwards order" << endl;
    for (vector<string>::iterator p = stringVector.end(); p > stringVector.begin(); )
    {
        p--;
        cout << "Next Vector Element is: " << *p << endl;
    }

    // Now random access 
    vector<string>::iterator p = stringVector.begin();

    // Remember from our discussion of vectors earlier in the semester
    // that you can also use the array index operator to access data
    cout << "Here comes the vector in forward order (with random access of iterator)" << endl;
    for (int i=0; i < stringVector.size(); i++)
    {
        cout << "Next Vector Element is: " << p[i] << endl;
    }

    // You can also do random access directly off of the vector variable itself
    cout << "Here comes the vector in forward order (with random access off of vector variable)" << endl;
    for (int i=0; i < stringVector.size(); i++)
    {
        cout << "Next Vector Element is: " << stringVector[i] << endl;
    }

    // This will cause an exception to be thrown because our vector does not have 23 elements!
    cout << stringVector.at(22);
}