//
// CS2024 -- Lecture #11, Demo 4
//
// Shape base class
//

// "Include Gaurd"
#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

using namespace std;

class Shape
{
     public:
        virtual double area() { std::cout << "I don't know" << std::endl; return 0;}// = 0;
        virtual std::string dimensions() { std::cout<< "I don't know" << std::endl;
        return "I don't know"};// = 0;
};

#endif

