//
// CS 2024 -- Lecture #2
//
// Demo #1: Relational Operators and Conditionals
//

#include <iostream>

// Here's our main function
int main (int argc, char * const argv[]) 
{
	// First, declare two integer variables to be used
	int j;
	int k;   
	
	// Now, read in one at a time, with a prompt
	std::cout << "Enter Integer #1: ";
	std::cin >> j;
	
	std::cout << "Enter Integer #2: ";
	std::cin >> k;
	
	// Next, print out the results of applying 
	// conditional operators to the two numbers

	// Apply <
	if (j < k)
		std::cout << j << " is less than " << k << std::endl;
	else
		std::cout << j << " is NOT less than " << k << std::endl;

	// Apply >
	if (j > k)
		std::cout << j << " is greater than " << k << std::endl;
	else
		std::cout << j << " is NOT greater than " << k << std::endl;

	// Apply ==
	if (j == k)
		std::cout << j << " is equal to " << k << std::endl;
	else
		std::cout << j << " is NOT equal to " << k << std::endl;
	
    return 0;
}
