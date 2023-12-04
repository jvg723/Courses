// cs 2024 -- assignment 2

#include <iostream>
using namespace std;

// Declare global variable for user name
std::string name = "";

// Functions 
void printmenu();
int promptUser();
bool takeAction(int choice);
void evaluateEligibility(int age);

// main program
int main (int argc,char *argv[])
{
    bool keepGoing = true;
    int choice = 0;

    while (keepGoing) {
        printmenu();
        choice = promptUser();
        keepGoing = takeAction(choice);
    }
}

// print menu function
void printmenu()
{
    std::cout <<  "MAIN MENU"           << std::endl 
               << "---------------------"  << std::endl
               << "1) Enter name"          << std::endl
               << "2) Voting Eligibility " << std::endl
               << "3) Quit"                << std::endl;
}

// prompt user function
int promptUser()
{
    int input; // User input
    
    std::cout << "Enter Choice: " << std::flush; std::cin  >> input; // Enter user choice
    
    return input; 
}

// take action function
bool takeAction(int choice)
{
    bool check; // checking if menu should still be printed

    // Check user input
    switch (choice)
    {
        case 1:
            std::cout << "Enter name: " << std::flush; std::cin >> name;
            check = true;
            break;
        case 2:
        {
            int age; // input for user age
            if (name.length() == 0){
                std::cout <<  "I don't know who you are!" << std::endl;
                check = true;
                break;
            } else{
                std::cout << "Hello, enter your age: " << std::flush; std::cin  >> age;
                evaluateEligibility(age);
                check = true;
                break; 
            }
        }
        case 3:
            std::cout <<  "All done!" << std::endl;
            check = false;
            break; 
    }

    return check;
}

// funciton to evaluate if someone is old enough to vote
void evaluateEligibilty(int age)
{
    if (age < 18)
    {
        std::cout << "You CANNOT vote." << std::endl;
    } else{
        std::cout << "You CAN vote!" << std::endl;
    }

}