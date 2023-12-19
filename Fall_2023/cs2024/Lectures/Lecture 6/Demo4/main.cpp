//
// CS2024 -- Lecture #9
//
// Demo #4 -- Class Pointers

#include <iostream>
using namespace std;  //introduces namespace std

#include "Course.h"

int main(int argc, char *argv[])
{	
	// Allocate a local variable of type "pointer to Course"
	//   and initialize it with a new instance of Course
	Course *cs2024 = new Course;

	if (cs2024 == NULL)
	  {
	    cout << "What a crappy computer, couldn't even allocate one instance" << endl;
	    return -1;
	  }

	// Access member functions in Course from the local variable
	cs2024->setCourseName("CS 2024");
	(*cs2024).setInstructor("DiNapoli");
	(*cs2024).setStudentCount(120);
	
	cout << "cs2024->name = " << (*cs2024).getCourseName() << endl;
	cout << "cs2024->instructor = " << cs2024->getInstructor() << endl;
	cout << "cs2024->numStudents = " << cs2024->getStudentCount() << endl;
	
	// Delete when we're done!
	delete cs2024;
	return 0;
}

