//
// CS2024 -- Lecture #11, Demo 5
//
// Square class
//
#include <iostream>
#include <sstream> // needed for items below
#include "Shape.h"

using namespace std;

class Ellipse : public Shape
{
    public:
        Ellipse()
        {
            major_radius = 0;
            minor_radius = 0;
        }

        Ellipse(double major, double minor)
        {
            major_radius = major_radius;
            minor_radius = minor_radius;
        }

        void setDimensions(double major, double minor)
        {
            major_radius = major_radius;
            minor_radius = minor_radius;
        }

        virtual double area() 
        {
            return 3.14 * major_radius * minor_radius;
        }

        virtual string dimensions()
        {
            // ostringstream is a string we can treat as a stream
            ostringstream oss;
            oss << "I'm a ELLIPSE. Major Radius: " << major_radius << ", minor radius: " << minor_radius;
            return oss.str();
        }

    private:
        double major_radius;
        double minor_radius;
};