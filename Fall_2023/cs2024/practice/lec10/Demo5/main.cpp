//
// CS2024:  Lecture #10, Demo 5
//
// Virtual Functions
//
#include <iostream>

using namespace std;  //introduces namespace std

#include "Person.h"

// Here's the Student class (derived)
class Student: public Person
{
public:
    Student() { studentID = 0; }
    Student(int id) { studentID = id; }
    void printInfo();
    int  getId() { return studentID; }
private:
   int  studentID;
};


void Student::printInfo()
{
    cout << "Student ID: " << studentID << endl;
}

//
// Here's the Instructor class (derived)
//
class Instructor: public Person
{
public:
    Instructor() { employeeID = 0; }
    Instructor(int id) { employeeID = id; }
    int getId() { return employeeID; }
private:
    int employeeID;
};


//
// And now a global function that prints out a 
// Person's info
//
void printPersonInfo(Person &aPerson)
{
    aPerson.printInfo();
}


int main()
{	
    Student aStudent(33445);
    Instructor anInstructor(12345);
    
    // Now set the information.  Remember, setInfo() is 
    // defined in the "Person" class
    cout << "First, the student..." << endl;
    aStudent.setInfo("Joe Student","166 Phelps Lane",
					 "555-1212");
    printPersonInfo(aStudent);
	
    cout << endl << "Now for the instructor: " << endl;
    anInstructor.setInfo("Ron DiNapoli", "441B Gates Hall", "555-1313");
    printPersonInfo(anInstructor);
    return 0;
}

