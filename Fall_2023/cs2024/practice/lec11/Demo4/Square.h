//
// CS2024 -- Lecture #11, Demo 3
//
// Square class
//
#include <iostream>
#include <sstream> // needed for items below
#include "Shape.h"

using namespace std;

class Square : public Shape
{
    public:
        Square()
        {
            side = 0;
        }

        Square(double side)
        {
            this->side = side;
        }

        void setDimensions(double side)
        {
            this->side = side;
        }

        virtual double area() 
        {
            return side * side;
        }

        virtual string dimensions()
        {
            // ostringstream is a string we can treat as a stream
            ostringstream oss;
            oss << "I'm a SQUARE. Sides: " << side;
            return oss.str();
        }

    private:
        double side;
};