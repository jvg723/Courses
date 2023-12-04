// Header files for menu class

#include <iostream>

using namespace std;

enum class MenuChoice 
{
    kShowCourseInfo,
    kChangeCourseName,
    kChangeCourseInstructor,
    kChangeCourseNumStudents,
    kQuit,
    kInvalidChoice
};

class Menu
{
    public:
        void displayMenu();
        // MenuChoice promptUser();
};




