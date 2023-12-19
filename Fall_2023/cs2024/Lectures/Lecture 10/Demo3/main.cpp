//
// CS2024: Lecture #10, Demo 3
//
// Redefining Base Class Members
//

#include <iostream>

// Allows us to access all symbols in the
// std namespace without having to prefix them with "std::"
using namespace std;  

#include "Person.h"

// Here's the Student class (derived)
class Student: public Person
{
public:
    Student() { studentID = 0; }
    void printInfo();
    int  getId() { return studentID; }
private:
    int  studentID;
};


void Student::printInfo()
{
    cout << "Student ID: " << studentID << endl;
}


class Instructor: public Person
{
public:
    Instructor() { employeeID = 0; }
    int getId() { return employeeID; }
private:
    int employeeID;
};


int main()
{	
    Student aStudent;
    Instructor anInstructor;
    
    // Now set the information.  Remember, setInfo() is 
    // defined in the "Person" class
    cout << "First, the student..." << endl;
    aStudent.setInfo("Joe Student","166 Phelps Lane",
					 "555-1212");
    aStudent.printInfo();
	
    cout << endl << "Now for the instructor: " << endl;
    anInstructor.setInfo("Ron DiNapoli", "441B Gates Hall", "555-1313");
    anInstructor.printInfo();
    return 0;
}

