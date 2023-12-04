// cs 2024 -- assignment 1

#include <iostream>
#include <string>

using namespace std;

//Here's our main function
int main (int argc, char * const argv[])
{
    // First, declare two variabel to be used
    int choice;   // Choice input from user
    int age;      // age of user
    std::string name = "";  // User name
    int menu = true; 

    // Use a while loop
    while (menu == true)
    {
        std::cout <<  "MAIN MENU"           << std::endl 
                << "---------------------"  << std::endl
                << "1) Enter name"          << std::endl
                << "2) Voting Eligibility " << std::endl
                << "3) Quit"                << std::endl;
        std::cout << "Enter Choice: " << std::flush; std::cin  >> choice;

        // Use switch statement
        switch (choice)
        {
            case 1:
                std::cout << "Enter name: " << std::flush; std::cin >> name;
            case 2:
                if (name.length() == 0){
                    std::cout <<  "I don't know who you are!" << std::endl;
                } else{
                    std::cout << "Hello, enter your age: " << std::flush; std::cin  >> age;
                }
            case 3:
                std::cout <<  "All done!" << std::endl;
                menu = false;
        }
    }

    return 0;
}