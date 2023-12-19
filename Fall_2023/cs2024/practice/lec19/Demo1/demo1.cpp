//
// CS2024 -- Lecture #19, Demo 1
//
// R-value and L-value References
//

#include <iostream>

// global1Func takes an lvalue reference (&)
void globalFunc1(int &value)
{
    value = 5;
}

// global2Func taks an rvalue reference (&&)
void globalFunc2(int &&value)
{
    // OK, updating an rvalue this way doesn't make much sense
    // but we're just demonstrating syntax here
    value = 10;
}

int main(int argc, char *argv[])
{
    int x = 0;

    // Since globalFunc1 is expecting an lvalue reference, pass it an lvalue
    globalFunc1(x);

    // Can't pass it an r-value, so if you uncomment the line below you will
    // get a compiler error
    // globalFunc1(4);

    std::cout << "x is now " << x << std::endl;

    // since globalFunc2 is execptinng an rvalue reference, pass it an rvalue
    globalFunc2(5);

    // Can't pass it an l-value, so if you uncomment the line below you will
    // get a compiler error
    globalFunc2(x);
}