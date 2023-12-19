//
// CS2024 -- Lecture #11, Demo 3
//
// Triangle class
//
#include <iostream>
#include <sstream> // needed for items below
#include <cmath>
#include "Shape.h"

using namespace std;

class Triangle : public Shape
{
    public:
        Triangle()
        {
            side1 = 0;
            side2 = 0;
            side3 = 0;
        }

        Triangle(double side1, double side2, double side3)
        {
            this->side1 = side1;
            this->side2 = side2;
            this->side3 = side3;
        }

        ~Triangle() 
        {
            std::cout << "In Triangle Destructor"<< std::endl;
        }

        void setDimensions(double side)
        {
            this->side1 = side1;
            this->side2 = side2;
            this->side3 = side3;
        }

        virtual double area() 
        {
            double perimeter = side1 + side2 + side3;
            double p = perimeter/2.0;
            return sqrt(p*(p-side1)*(p-side2)*(p-side3));
        }

        virtual string dimensions()
        {
            // ostringstream is a string we can treat as a stream
            ostringstream oss;
            oss << "I'm a TRIANGLE. Side1: " << side1 << ", Side2: " << side2 << ", Side3: " << side3;
            return oss.str();
        }

    private:
        double side1;
        double side2;
        double side3;
};