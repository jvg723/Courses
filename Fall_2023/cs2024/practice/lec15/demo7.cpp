//
// CS2024 Lecture #15, Demo 7
//
// Stack adapters
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main (int argc, char * const argv[]) 
{
    // Here's a simple stack
    stack<int> s;
    int theData[] = { 16, 35, 99, 56, 44 };

    // Push the data onto the stack
    for (int i=0; i<5; i++)
    {
        s.push(theData[i]);
    }

    // Now the data is on the stack, lets take a look at the top
    cout << "Stack has " << s.size() << " elemnts. " << endl;
    cout << "Top of stack is: " << s.top() << endl;

    // Looking at the top of the stack does not pop it off.  
	// We need to do that manually.
    s.pop();

    // Now, let's look at the stack again:
	// Now the data is on the stack, let's look at the top
	cout << "Stack has " << s.size() << " elements. " << endl;
	cout << "Top of stack is: " << s.top() << endl;

    // Now, do the whole thing over again with a different 
	// underlying container
	// Here's a simple stack
    stack<int,vector<int> > s1;

    // Push the data onto the stack
    for (int i=0; i<5; i++)
    {
        s1.push(theData[i]);
    }

     // Now the data is on the stack, lets take a look at the top
    cout << "Stack has " << s1.size() << " elemnts. " << endl;
    cout << "Top of stack is: " << s1.top() << endl;

    // Looking at the top of the stack does not pop it off.  
	// We need to do that manually.
    s1.pop();

    // Now, let's look at the stack again:
	// Now the data is on the stack, let's look at the top
	cout << "Stack has " << s1.size() << " elements. " << endl;
	cout << "Top of stack is: " << s1.top() << endl;
}
