// 
// CS 2024 -- Lecture #5
// 
// Demo #2 -- Simple Class

#include <iostream>
#include <string>

using namespace std;

// Declare a new class named "Course"
class Course
{
public:
        // define the member functions
        int getStudentCount()
        {
            return numStudents;
        }

        // define the member varaibles
        string name;
        string instructor;
        int numStudents;
};

int main(int argc, char *argv[])
{
    // Declare an instance of the Course "class"
    Course cs2024;

    // Assign values to the member variables in the class
    cs2024.name = "CS 2024";
    cs2024.instructor = "Joe Giliberto";
    cs2024.numStudents = 120;

    // Echo back the values to stored in the structure
    cout << "cs2024.name = " << cs2024.name << endl;
    cout << "cs2024.instructor = " << cs2024.instructor << endl;
    cout << "cs2024.numStudents = " << cs2024.numStudents << endl;

    // Call a member function in the class
    cout << "Number of students is " << cs2024.getStudentCount() << endl;
    return 0;
}