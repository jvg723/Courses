//
// CS2024:  Lecture #5
//
// Demo #5 -- Member Function Definitions
//

#include <iostream>

using namespace std;  //introduces namespace std

class Course
{
public:
	// define the member functions
	int getStudentCount();
	string getCourseName();
	string getInstructor();
	void setStudentCount(int count);
	void setCourseName(string theName);
	void setInstructor(string theInstructor);
	
private:
	// define the member variables
	string name;
	string instructor;
	int numStudents;
};

// Define the getter/setter functions outside of the class definition
int Course::getStudentCount()
{
	return numStudents;
}

string Course::getCourseName()
{
	return name;
}

string Course::getInstructor()
{
	return instructor;
} 

void Course::setStudentCount(int count)
{
	numStudents = count;
}

void Course::setCourseName(string theName)
{
	name = theName;
}

void Course::setInstructor(string theInstructor)
{
	instructor = theInstructor;
}


int main(int argc, char *argv[])
{	
	// Declare an instance of the Course class
	Course cs2024;
	
	// Provide initial values for the member variables through
	// the use of the setter functions
	cs2024.setCourseName("CS 2024");
	cs2024.setInstructor("Ron DiNapoli");
	cs2024.setStudentCount(120);
	
	// Echo back the data stored in the member variables.
	// Access data via the getter functions
	cout << "cs2024.name = " << cs2024.getCourseName() << endl;
	cout << "cs2024.instructor = " << cs2024.getInstructor() << endl;
	cout << "cs2024.numStudents = " << cs2024.getStudentCount() << endl;
	
	return 0;
}

