//
// CS2024 Lecture #12, Demo 2
//
// Mulitple cathches
//

#include <iostream>

using namespace std;  //introduces namespace std
#include <string>

void executeSomeFunction()
{
    // We can force a throw exception to a particular type with a case
    throw (float)( 1.4 );
    // throw 1.4;
}

int main()
{
    try 
    {
        executeSomeFunction();      // Arbitrary function

    }
    catch(int x) {  cout<< "caught INTEGER: " << x << endl; }
    catch(float  f) {  cout<< "caught FLOAT: " << f << endl; }
    catch(double f) {  cout<< "caught DOUBLE: " << f << endl; }
    catch(string s) {  cout<< "caught STRING: " << s << endl; }
    catch(...) {  cout<< "Generic exception caught" << endl; }
}