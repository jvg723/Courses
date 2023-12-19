//
// CS2024 -- Lecture #11, Demo 1
//
// main.cpp
//

#include <iostream>

#include "Shape.h"

using namespace std;

// Introduce #define -- allows us to assign a literal value to a symbol
#define MAX_SHAPES 10

int main(int argc, char *argv[])
{
    Shape *shapeArray[MAX_SHAPES];
    int shapeCount = 0;

    // Allocate shapes for our array (assume all allocations succeed)
    shapeArray[0] = new Shape();
    shapeArray[0]->setShapeType(SQUARE);
    shapeArray[0]->setSquareDimensions(5);
    shapeCount++;

    shapeArray[1] = new Shape();
    shapeArray[1]->setShapeType(RECTANGLE);
    shapeArray[1]->setRectangleDimensions(5,6);
    shapeCount++;

    shapeArray[2] = new Shape();
    shapeArray[2]->setShapeType(TRIANGLE);
    shapeArray[2]->setTriangleDimensions(4,5,6);
    shapeCount++;

    shapeArray[3] = new Shape();
    shapeArray[3]->setShapeType(CIRCLE);
    shapeArray[3]->setCircleDimensions(5);
    shapeCount++;

    // Print out shape dimensions
    for (int i=0; i<MAX_SHAPES; i++)
    {
        cout << "Data for Shape #" << i << endl;
        cout << " Dimensions are: " << shapeArray[i]->dimensions() << endl;
        cout << " Area is: " << shapeArray[i]->area() << endl;
    }

    // Clean up
    for (int i=0; i<shapeCount; i++)
    delete shapeArray[i];
}