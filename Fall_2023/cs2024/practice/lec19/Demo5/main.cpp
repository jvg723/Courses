//
// CS2024 -- Lecture #19, Demo #3
//
// main.cpp
//

#include <iostream>
#include "SimpleIntArray.h"

SimpleIntArray createSimpleIntArray()
{
	SimpleIntArray array(3);
	array[0] = 10;
	array[1] = 20;
	array[2] = 30;

	std::cout << "createSimpleIntArray: about to return array" << std::endl;

	return array; // Create an rvalue
}

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
	
	// Line below needs C++1r or later to complie
	SimpleIntArray sia3( createSimpleIntArray() );

	std::cout << "sia2 is " << sia2 << std::endl;
	std::cout << "sia3 is " << sia3 << std::endl;
}

