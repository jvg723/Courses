//
// CS2024 -- Lecture #5
//
// Demo #4 -- Getters and Setters
//
#include <iostream>

using namespace std;  //introduces namespace std

class Course
{
public:
	// define the member functions
	int getStudentCount()
	{
		return numStudents;
	}
	
	string getCourseName()
	{
		return name;
	}
	
	string getInstructor()
	{
		return instructor;
	} 
	
	void setStudentCount(int count)
	{
		numStudents = count;
	}
	
	void setCourseName(string theName)
	{
		name = theName;
	}
	
	void setInstructor(string theInstructor)
	{
		instructor = theInstructor;
	}
	
private:
	// define the member variables
	string name;
	string instructor;
	int numStudents;
};


int main(int argc, char *argv[])
{	
	// Declare an instance of the Course "class"
	Course cs2024;
	
	// Provide initial values for the member variables through the 
	// "setter" functions
	cs2024.setCourseName("CS 2024");
	cs2024.setInstructor("Ron DiNapoli");
	cs2024.setStudentCount(120);
	
	// Echo back the values stored in the member variables.
	// Access them via the "getter" functions
	cout << "cs2024.name = " << cs2024.getCourseName() << endl;
	cout << "cs2024.instructor = " << cs2024.getInstructor() << endl;
	cout << "cs2024.numStudents = " << cs2024.getStudentCount() << endl;
	
	return 0;
}


