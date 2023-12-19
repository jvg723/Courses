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
        // Destructor is virtual so that if we delete a pointer to the
        // Shape base class any destructors in a derived class that exist 
        // will be called
        virtual ~Shape() { std::cout << "Destructor base class" << std::endl;};

        virtual double area() = 0;
        virtual std::string dimensions() = 0;
};

#endif

