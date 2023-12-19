//
//  CS2024:  Lecture #10, Demo 2
//
//  Protected Members
//
//  WARNING:  THIS CODE WILL NOT COMPILE!
//            (If some code is left uncommented in main())
//
// Note:  All classes are defined in this one file to make the demo simpler, 
//        ordinarily we'd have each class in its own file(s)        
//

#include <iostream>

using namespace std; 

// Declare a base class named "Person"
class Person
{
    public:
        void setInfo(string Name, string Addr, string phone);
    protected:
        string name;
        string address;
        string phone;
};

//Here's the defintion for the Person::setInfo() member function
void Person::setInfo(string Name, string Addr, string Phone)
{
    name = Name;
    address = Addr;
    phone = Phone;
}

// Derive a class callsed "Student"
class Student: public Person
{
    public:
        Student (int myId){studentID = myId;}
        void printInfo();
        int getId() { return studentID; }
    private:
        int studentID;
};

// here's the Student::printInfo() member function
void Student::printInfo()
{
    cout << "Name:  " << name << endl;    // name, address and
    cout << "Addr:  " << address << endl; // phone are defined 
    cout << "Phone: " << phone << endl;   // in the base class
    cout << "ID:    " << studentID << endl;
}

int main(int argc, char *argv[])
{	
  Student aStudent(1234);
	
    // Will the following work?  No!   Since name, address and phone
    // are *protected* members of the base class, they can't be accessed
    // directly from "outside" the base or derived class.
    // Comment out the next three lines in order to see the demo compile and run
    //aStudent.name = "Joe Student";          // ??
    //aStudent.address = "166 Phelps Lane";   // ??
    //aStudent.phone = "555-1212";            // ??
	
    // Now set the information.  Remember, setInfo() is 
    // defined in the "Person" class
    aStudent.setInfo("Joe Student","166 Phelps Lane",
				 "555-1212");
    aStudent.printInfo();
    return 0;
}