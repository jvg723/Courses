// 
// CS 2024 -- Lecture #1
//
// Demo #2: Read Integers and Add

#include <iostream> 

int main (int argc, char *argv[])
{
        // First, declare two integer varaibles to be used
        int j;
        int k; 

        //Now, read in one at a time with a prompt
        std::cout << "Enter Integer #1: ";
        std::cin >> j;

        std::cout << "Enter Integer #2: ";
        std::cin >> k; 

        //Next, print out the results of adding the two.
        std::cout << j << " + " << k << " = " << j+k << std::endl;

    return 0; 
    
}