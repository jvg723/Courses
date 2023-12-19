//
// CS2024:  Lecture #16, Demo 1
//
// Calling Template Functions
//

#include <iostream>

using namespace std;  //introduces namespace std

// A simple base class and derived class with an overridde member
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
            cout << "I am a student!" << endl;
        }
};

// And now, a template:
template <class Somebody> void whoAmI(Somebody *x, Person *y)
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

    // What happens if Person::whoAMI() is declated virual?
    return 0;
}