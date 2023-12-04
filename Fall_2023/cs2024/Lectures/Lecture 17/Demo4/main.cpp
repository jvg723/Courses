//
// CS2024 -- Lecture #17, Demo 4
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

int main(int argc, char *argv[])
{
  ShapeBox shapeBox;
  
  cout << "We start with " << shapeBox.count() << " shapes in the box. " << endl;
  
  // Allocate shapes for our array (assume all allocations succeed)
  shapeBox.addShape( shared_ptr<Shape>(new Square(5)) );
  shapeBox.addShape( shared_ptr<Shape>(new Rectangle(5,6)) );
  shapeBox.addShape( shared_ptr<Shape>(new Triangle(4,5,6)) );
  shapeBox.addShape( shared_ptr<Shape>(new Circle(5)) );
  shapeBox.addShape( shared_ptr<Shape>(new Ellipse(6,8)) );

  // Show how many shapes are in box now
  cout << "We now have " << shapeBox.count() << " shapes in the box. " << endl;


  // Print out shape dimensions and area
  shapeBox.display();
    
  // Print out something just to show when the last line of the 
  // program has executed
  cout << "We're done!" << endl;
  
  // Since we are now using a shared_ptr to store our shape, the use_count
  // on all shared_ptr objects in the vector will drop to 0 when the 
  // shapeBox local variable goes out of scope.   Then, all of the 
  // pointers will be freed resulting in their destructors being called

}
