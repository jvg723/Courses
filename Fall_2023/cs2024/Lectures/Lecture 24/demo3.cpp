//
// CS2024 -- Lecture #24
//
// Demo #3:  structured binding/decomposition declarations
// C++17 or later
//

#include <iostream>

struct Person {
   std::string name;
   std::string phone;
   int age; 
};



int main(int argc,char *argv[])
{
	// With structures...
	struct Person aPerson;
	aPerson.name = "Ron";
	aPerson.phone = "555-1212";
	aPerson.age = 29;
	
	auto [n,p,a] = aPerson;
	
	std::cout << "Person data..." << std::endl;
	std::cout << n << std::endl;
	std::cout << p << std::endl;
	std::cout << a << std::endl;
	
	// With arrays
	int myArray[]{2,3,5};
	
	// Number of elements MUST match size of array
	auto [x,y,z] = myArray;

 	std::cout << std::endl << "Array data..." << std::endl;
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << z << std::endl;
	
	// Can declare elements by reference, then they refer to actual item instead of copy
	
	auto& [x1,y1,z1] = myArray;
	x1 = 9;
	y1 = 10;
	z1 = 11;
	
	std::cout << std::endl << "Updated array data..." << std::endl;
	std::cout << myArray[0] << std::endl;
	std::cout << myArray[1] << std::endl;
	std::cout << myArray[2] << std::endl;

	
}


