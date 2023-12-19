// 
// CS 2024 -- Lecture #6
// 
// Demo #7 -- Dynamic Allocation
//
#include <string>

// Here is the Course Class
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