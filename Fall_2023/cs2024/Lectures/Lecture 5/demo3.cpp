//
// CS 2024 -- Lecture #5
//
// Demo 3 -- Public and Private
//
// NOTE:  THIS CODE WILL NOT COMPILE!!!!
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
		
  private:
    // define the member variables
    string name;
    string instructor;
    int numStudents;
};


int main(int argc, char *argv[])
{	
    // Declare an instance fo the Course "class"
    Course cs2024;
	
    // Attempt to assign initial values to the member variables
    cs2024.name = "CS 2024";
    cs2024.instructor = "Ron DiNapoli";
    cs2024.numStudents = 120;
	
    // echo back what we just assigned
    cout << "cs2024.name = " << cs2024.name << endl;
    cout << "cs2024.instructor = " << cs2024.instructor << endl;
    cout << "cs2024.numStudents = " << cs2024.numStudents << endl;
	
    // Call a member function
    cout << "Number of students is " << cs2024.getStudentCount() << endl;
    return 0;
}

