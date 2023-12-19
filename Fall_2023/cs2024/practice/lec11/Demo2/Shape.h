//
// CS2024 -- Lecture #11, Demo 2
//
// Shape base class
//
#include <iostream>
#include <cmath>
#include <sstream> // needed for items below

using namespace std;

typedef enum
{
    UNKNOWN=0,
    SQUARE,
    TRIANGLE,
    RECTANGLE,
    CIRCLE
} ShapeType;

class Shape
{
    public:

        // Default constructor
        Shape()
        {
            type = UNKNOWN;
            length = 0;
            width = 0;
            radius = 0;
            base = 0;
        }

        // Set shape type and dimensions
        void setShapeType(ShapeType type)
        {
            this->type = type;
        }

        void setSquareDimensions(double side)
        {
            length = width = side;
        }

        void setRectangleDimensions(double length, double width)
        {
            this->length = length;
            this->width = width;
        }

        void setCircleDimensions(double radius)
        {
            this->radius = radius;
        }

        void setTriangleDimensions(double base, double side1, double side2)
        {
            this->base = base;
            // "overload" use of the length and width internally for side1/side2
            length = side1;
            width = side2;
        }

        double area ()
        {
            switch(type)
            {
                case SQUARE:
                case RECTANGLE:
                    return length * width;
                case TRIANGLE:
                    {
                        // Need Heron's formula
                        double perimeter = base + length + width;
                        double p = perimeter/2.0;
                        return sqrt(p*(p-base)*(p-length)*(p-width));
                    }
                case CIRCLE:
                    return 3.14 * radius * radius;
                default:
                    std::cout << "I have no idea what my area is!!!" << std::endl;
                    return 0;  // meaningless, we have no idea how to calculate the area!
            }
        }

        string dimensions()
        {
            // ostringstream is a string we can treat as a stream
            ostringstream oss;

            switch(type)
            {
                case SQUARE:
                    oss << "I'm a SQUARE. Sides: " << length;
                    return oss.str();
                case RECTANGLE:
                    oss << "I'm a RECTANGLE. Length: " << length << ", width: " << width;
                    return oss.str();
                case TRIANGLE:
                    oss << "I'm a TRIANGLE. Side1: " << length << ", Side2: " << width << ", base: " << base;
                    return oss.str();
                case CIRCLE:
                    oss << "I'm a CIRCLE. Radius: " << radius;
                    return oss.str();
                default:
                    return "UKNOWN -- NO DIMENSIONS";
            }
        }

    private:
        // Various dimensions
        double length;
        double width;
        double base;
        double radius;
        ShapeType type;
};

