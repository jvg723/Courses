//
// CS2024 -- Lecture #6
//
// Demo #7 -- Dynamic Allocation
//

#include <iostream>

using namespace std;  //introduces namespace std

// Bring in the definition for the Course class
#include "Course.h"

int main(int argc,char *argv[])
{	
	int numCourses;
	
	// Prompt the user for a course count
	cout << "Enter the number of courses you wish to create: ";
	cin >> numCourses;
     

	// Make sure they entered a valid number
	if (numCourses <= 0)
	{
		cout << "OK, you don't want to enter anything, I see..." << endl;
		return 0;
	}
	
	// declare and allocate the array
	Course *courses = new Course[numCourses];
	
	// Make sure the allocation succeeded
	if (courses == NULL)
	{
		cout << "Could not allocate memory for courses array " << endl; 
		return -1;
	}
	
	// Declare variables for reading data into
	string course;
	string instructor;
	int classSize;
	
	// For each course the user wants to create, enter data 
	// and then set the data in the Course class.
	for (int i=0; i<numCourses; i++)
	{
		cout << "Enter a course title: ";
		cin >> course;
		cout << "Enter the instructor's name: ";
		cin >> instructor;
		cout << "Enter the student count: ";
		cin >> classSize;
		cout << endl;
		
		(*(courses+i)).setCourseName(course);
		courses[i].setInstructor(instructor);
		i[courses].setStudentCount(classSize);
	}
	
	// Now just print out a list of classes
	cout << "Course List..." << endl;
	cout << "--------------" << endl;
	
	for (int k=0; k < numCourses; k++)
		cout << courses[k].getCourseName() << ", " << 
		courses[k].getInstructor() << ", " <<
		courses[k].getStudentCount() << endl;
	
	// don't forget to clean up!
	delete [] courses;  
}

