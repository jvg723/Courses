//
// CS2024 -- Lecture #19, Demo #3
//
// main.cpp
//

#include <iostream>
#include "SimpleIntArray.h"

int main(int argc,char *argv[])
{
	SimpleIntArray sia(5);
	
	sia[0] = 1;
	sia[1] = 3;
	sia[2] = 5;
	sia[3] = 7;
	sia[4] = 9;
	
	std::cout << "sia is: " << sia << std::endl;
	
	std::cout << "About to allocate sia2" << std::endl;
	SimpleIntArray sia2(sia);
	
	std::cout << "About to allocate sia3" << std::endl;
	SimpleIntArray sia3;
	
	sia3 = sia;
	
	std::cout << "sia2 is " << sia2 << std::endl;
	std::cout << "sia3 is " << sia3 << std::endl;
}

