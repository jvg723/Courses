// 
// CS 2024 -- Lecture #6
// 
// Demo #4 -- Course Pointers
//
#include <iostream>
using namespace std;
#include "Course.h"

int main(int argc, char *argv[])
{
    // Allocate a local variable of type "pointer to Course"
    // and initalize it with a new instance of Course
    Course *cs2024 = new Course;

    if (cs2024 == NULL)
    {
        cout << "what a crappy computer, couldn't even allocate one instance" << endl;
        return -1;
    }

    // Access member functions in Course from local variable
    cs2024->setCourseName("CS 2024");
    (*cs2024).setInstructor("Giliberto");
    (*cs2024).setStudentCount(120);

    cout << "cs2024->name = " << (*cs2024).getCourseName() << endl;
    cout << "cs2024->instructor = " << cs2024->getInstructor() << endl;
    cout << "cs2024->numStudents = " << cs2024->getStudentCount() << endl;

    // Delete when we're done
    delete cs2024;
    return 0;
}