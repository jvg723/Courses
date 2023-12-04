// Class for display menu and taking user input

#include "Menu.h" // header in local directory
// #include <iostream>

using namespace std;


// display menu function
void Menu::displayMenu()
{
    std::cout <<  "MAIN MENU"                    << std::endl 
               << "---------------------------"  << std::endl
               << "1) Show Course Info"          << std::endl
               << "2) Change Course Name "       << std::endl
               << "3) Change Course Instructor"  << std::endl
               << "4) Change Number of Students" << std::endl
               << "5) Quit"                      << std::endl;
}