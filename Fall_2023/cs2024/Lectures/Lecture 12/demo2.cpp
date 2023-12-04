//
// CS2024 Lecture #12, Demo 2
//
// Multiple Catches
//

#include <iostream>

using namespace std;  //introduces namespace std
#include <string>

void executeSomeFunction()
{
  // We can force a thrown exception to a particular type with a cast
  //throw (float)( 1.4 );
  throw 1.4;
}

int main()
{
    try {
   	executeSomeFunction();		// Arbitrary function
    }
    catch(int x) { 	cout << "Caught INTEGER: " << x << endl; }
    catch(float f) {  cout << "Caught FLOAT: " << f << endl; }
    catch(double f) {  cout << "Caught DOUBLE: " << f << endl; }
    catch(string s) { cout << "Caught STRING: " << s << endl; }
    catch(...) { cout << "Generic exception caught" << endl; }
}
