//
// CS2024: Lecture 13, Demo #3
//
// C++11 Unified Initialization Syntax
//

#include <iostream>

int main(int argc, char *argv[])
{
    // C++11 Unified initialization syntax has you put the initial value to assign
    // to the variable immediately after it in curly braces
    int x{1};
    std::string str{"Hello World!"};
    int smallPrimes[]{2,3,4,7,11,13};

    // Check that these are initalized
    std::cout << "x is " << x << std::endl;
    std::cout << " str is " << std::endl;

    for (int i=0; i<6; i++)
    {
        std::cout << "smallPrimes[" << i << "]" << smallPrimes[i] << std::endl;
    } 
}