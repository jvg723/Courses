//
// CS2024 Lecture #12, Demo 1
//
// Simple Exception
//

#include <iostream>

using namespace std;  //introduces namespace std

// Error codes
enum MathErr {
    noErr,
    divByZero,
    genericOverflow
} ;

// divide function
float divide(float numerator,float denominator)
{
    if (denominator == 0)
      throw divByZero;

    // Comment out the throw above and uncomment this to see what happens when
    // you don't throw a MathErr
    //throw 1.4;
    return numerator/denominator;
}

// Test out exceptions!
int main()
{	
    try{
	cout << "5 / 2 is " << divide(5,2) << endl;
	cout << "2 / 0 is " << divide(2,0) << endl;
	cout << "4 / 1 is " << divide(4,1) << endl;
    }
    catch(MathErr x)
    {
	if (x == divByZero)
  	    cout << "Caught Divide by Zero error! " << endl;
	else
  	    cout << "Generic error caught! " << endl;
    }
    catch(...)
    {
    	cout << "We've been caught" << endl;
	// throw by itself re-throws the current exception
	// Uncomment the line below to see what happens when you don't catch an exception
	throw;
   }
	
	
    cout << "All done... " << endl;
	
    return 0;
}

