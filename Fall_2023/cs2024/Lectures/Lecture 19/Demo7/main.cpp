//
// CS2024 -- Lecture #19, Demo #7
//
// main.cpp
//

#include <iostream>
#include <vector>
#include "SimpleIntArray.h"



int main(int argc,char *argv[])
{
	// Declare three SimpleIntArray objects
	SimpleIntArray sia(3);
	
	sia[0] = 1;
	sia[1] = 3;
	sia[2] = 5;
	
	SimpleIntArray sia2(3);
	
	sia2[0] = 2;
	sia2[1] = 4;
	sia2[2] = 6;
	
	SimpleIntArray sia3(5);

	sia3[0] = 0;
	sia3[1] = 1;
	sia3[2] = 2;
	sia3[3] = 3;
	sia3[4] = 4;	

	// Now declare a vector that holds SimpleIntArray objects
	std::vector<SimpleIntArray> siaVector;
	
	// Now put two of the SimpleIntArray objects into the vector
	std::cout << "SimpleIntArray objects created, about to use push back to put two in the vector" << std::endl;
	siaVector.push_back(sia);
	siaVector.push_back(sia2);
	
	std::cout << "About to insert third SimpleIntArray into vector" << std::endl;
	// Insert element into second position
	siaVector.insert(siaVector.begin()+1,sia3);
	
	std::cout << "end of main" << std::endl;
}

