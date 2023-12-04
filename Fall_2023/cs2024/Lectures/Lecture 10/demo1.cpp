//
// CS2024: Lecture #10, Demo 1
//
// Simple Inheritance
//
// Note:  All classes are defined in this one file to make the demo simpler,
//        ordinarily we'd have each class in its own file(s)
//

#include <iostream>

// Allows us to use all symbols in std namespace
// without the "std::" prefix
using namespace std;  

// Declare a base class named "Person"
class Person
{
public:
    string name;
    string address;
    string phone;
};

// Derive a class called "Student"
class Student: public Person
{
public:
    int studentID;
};

// Simply show that you can access member variables
// from the base class and derived class as if they
// all existed in the derived class
int main()
{	
    Student oneStudent;
	
    oneStudent.name = "Joe Student";
    oneStudent.address = "166 Phelps Lane";
    oneStudent.phone = "555-1212";
    oneStudent.studentID = 99999;
	
    cout << "oneStudent.name =      " << oneStudent.name << endl;
    cout << "oneStudent.address =   " << oneStudent.address << endl;
    cout << "oneStudent.phone =     " << oneStudent.phone << endl;
    cout << "oneStudent.studentID = " << oneStudent.studentID << endl;
	
    return 0;
}

