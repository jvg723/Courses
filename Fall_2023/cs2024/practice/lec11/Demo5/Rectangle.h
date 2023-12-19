//
// CS2024 -- Lecture #11, Demo 3
//
// Rectangle class
//
#include <iostream>
#include <sstream> // needed for items below
#include "Shape.h"

using namespace std;

class Rectangle : public Shape
{
    public:
        Rectangle()
        {
            length = 0;
            width = 0;
        }

        Rectangle(double length, double width)
        {
            this->length = length;
            this->width = width;
        }

        void setDimensions(double length, double width)
        {
            this->length = length;
            this->width = width;
        }

        virtual double area() 
        {
            return length * width;
        }

        virtual string dimensions()
        {
            // ostringstream is a string we can treat as a stream
            ostringstream oss;
            oss << "I'm a RECTANGLE. Length: " << length << ", width: " << width;
            return oss.str();
        }

    private:
        double length;
        double width;
};