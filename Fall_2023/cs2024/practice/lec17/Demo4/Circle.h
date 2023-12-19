//
// CS2024 -- Lecture #11, Demo 3
//
// Circle class
//
#include <iostream>
#include <sstream> // needed for items below
#include "Shape.h"

using namespace std;

class Circle : public Shape
{
    public:
        Circle()
        {
            radius = 0;
        }

        Circle(double radius)
        {
            this->radius = radius;
        }

        ~Circle() 
        {
            std::cout << "In Circle Destructor" << std::endl;
        }

        void setDimensions(double radius)
        {
            this->radius = radius;
        }

        virtual double area() 
        {
            return 3.14 * radius * radius;
        }

        virtual string dimensions()
        {
            // ostringstream is a string we can treat as a stream
            ostringstream oss;
            oss << "I'm a CIRCLE. Radius: " << radius;
            return oss.str();
        }

    private:
        double radius;
};