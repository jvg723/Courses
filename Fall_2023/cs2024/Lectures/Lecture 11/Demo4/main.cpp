//
// CS2024 -- Lecture #11, Demo 4
//
// main.cpp
//

#include <iostream>

#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

using namespace std;

// Introducing #define -- allows us to assign a literal value to a symbol
#define MAX_SHAPES 10

int main(int argc, char *argv[])
{
  Shape *shapeArray[MAX_SHAPES];
  int shapeCount = 0;

  // Allocate shapes for our array (assume all allocations succeed)
  shapeArray[shapeCount++] = new Square(5);
  shapeArray[shapeCount++] = new Rectangle(5,6);
  shapeArray[shapeCount++] = new Triangle(4,5,6);
  shapeArray[shapeCount++] = new Circle(5);

  // Print out shape dimensions and area
  for (int i=0; i<shapeCount; i++) {
    cout << "Data for Shape #" << i << endl;
    cout << "  Dimensions are: " << shapeArray[i]->dimensions() << endl;
    cout << "  Area is: " << shapeArray[i]->area() << endl;
  }

  // Clean up
  for (int i=0; i<shapeCount; i++)
    delete shapeArray[i];
}
