//
// CS2024 -- Lecture #11, Demo 1
//
// main.cpp
//

#include <iostream>

#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Ellipse.h"

#include "ShapeBox.h"

using namespace std;

// Introduce #define -- allows us to assign a literal value to a symbol
#define MAX_SHAPES 10

int main(int argc, char *argv[])
{
    ShapeBox shapeBox;

    cout << "We start with " << shapeBox.count() << " shapes in the box. " << endl;

    // Allocate shapes for our array 
    shapeBox.addShape(new Square(5) );
    shapeBox.addShape(new Rectangle(5,6) );
    shapeBox.addShape(new Triangle(4,5,6) );
    shapeBox.addShape(new Circle(5) );
    shapeBox.addShape(new Ellipse(6,8) );

    // Show how many shapes in in box now
    cout << "We now have " << shapeBox.count() << " shapes in the box. " << endl;

    // Print out shape dimensions and area
    shapeBox.display();

    // Now we have a problem.   The ShapeBox class doesn't 
    // define a getter to retrieve all the pointers so that 
    // we can free them.
    
    // We could make it a requirement that the ShapeBox free the pointers,
    // but that goes against a good practice that whomever allocates the pointers
    // should be the one to take responsibility for freeing them  As this code is 
    // written now, those shape pointers will never be freed 

    // Print out something just to show when the last line of the 
    // program has executed
    cout << "We're done!" << endl;

}