//
// CS2024 -- Lecture #17, Demo 3
//
// ShapeBox.h
//

#include <iostream>
#include <vector>

#include "Shape.h"

using namespace std;

class ShapeBox
{
    public:
            int count() { return shapes.size(); }
            void addShape(Shape *shapePtr) { shapes.push_back(shapePtr); }
            void display ()
            {
                for (auto shape : shapes)
                {
                    cout << shape->dimensions() << endl;
                }
            }

    private:
            vector<Shape *> shapes;
};