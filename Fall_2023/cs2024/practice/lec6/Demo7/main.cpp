// 
// CS 2024 -- Lecture #6
// 
// Demo #7 -- Dynamic Allocation
//
#include <iostream>
using namespace std;
#include "Course.h"

int main(int argc, char *argv[])
{
    int numCourses;

    // Prompt the user for a course cout
    cout << "Enter the number of courses you wish to create: ";
    cin >> numCourses;

    // Make sure they entered a valid number
    if (numCourses <= 0)
    {
        cout << "Ok, you don't want to enter anything, I see.." << endl;
    }

    // declare and allocate the array
    Course *courses = new Course[numCourses];

    // Make sure the allocation succeeded 
    if (courses == NULL)
    {
        cout << "Could not allocate memory for course array" << endl;
        return -1;
    }

    // Declare variables for readin data into
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

    // don't foet to clean up!
    delete [] courses;
}