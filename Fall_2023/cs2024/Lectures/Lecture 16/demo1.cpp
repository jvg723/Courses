//
// CS2024:  Lecture #16, Demo 1
//
// Calling Template Functions
//

#include <iostream>

using namespace std;  //introduces namespace std

// A simple base class and derived class with an overridden member
class Person
{
public:
  void whoAmI()
  {
    cout << "I am a Person!" << endl;
  }
};

class Student : public Person
{
public:
  void whoAmI()
  {
    cout << "I am a Student!" << endl;
  }
};

// And now, a template:
template <class Somebody> void whoAmI(Somebody *x,Person *y)
{
  x->whoAmI();
  y->whoAmI();
}

int main()
{	
    Student aStudent;
    
    // Call the template function once without specifying types
    cout << "No special type specification " << endl;
    whoAmI(&aStudent,&aStudent);
    
    //  Now call with type specification
    cout << "Coercing first argument to Person" << endl;
    whoAmI<Person>(&aStudent,&aStudent);
    
    // What happens if Person::whoAmI() is declared as virtual?
	return 0;
}

