// 
// CS 2024 -- Lecture #5
// 
// Demo #1 -- Simple C Structures

#include <iostream>
#include <string>
using namespace std;

// The following syntax is the C-style mechanism for creating data structures
typedef struct 
{
    string name;
    string instructor;
    int numStudents;
} Course;

int main(int argc, char * const argv[])
{
    // Declare an instance of a "Course" data type
    Course cs2024;

    // Assign initial values to the feilds in the structure
    cs2024.name = "CS 2024";
    cs2024.instructor = "Joe Giliberto";
    cs2024.numStudents = 120;

    // Echo back the values to stored in the structure
    cout << "cs2024.name = " << cs2024.name << endl;
    cout << "cs2024.instructor = " << cs2024.instructor << endl;
    cout << "cs2024.numStudents = " << cs2024.numStudents << endl;

    return 0;
}