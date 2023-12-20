//
// CS2024 Lecture #22, Demo 6
//
// Simple stream manipulator -- unstuck!
//

#include <iostream>
#include <iomanip>

int main (int argc, char * const argv[])
{
    std::cout << std::hex << "This number is " << 15 << std::endl;
    std::cout << std::dec << "Back to base 10: " << 15 << std::endl;

    // Swtich to octal using setbase(8) instead of std::oct
    std::cout << std::setbase(8) << "And this number is " << 32 << std::endl;

    // This does not work
    std::cout << std::setbase(2) << "And this number is " << 32 << std::endl;
}