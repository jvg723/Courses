//
// CS2024 -- Lecture #11, Demo 5
//
// Circle class
//
#include <iostream>
#include <sstream>
#include "Shape.h"

class Circle : public Shape 
{
 public:
  Circle() {
    radius = 0;
  }

  Circle(double radius) {
    this->radius = radius;
  }

  void setDimensions(double radius) {
    this->radius = radius;
  }

  virtual double area() 
  {
    return 3.14 * radius * radius;
  }

  virtual std::string dimensions()
  {
    std::ostringstream oss;

    oss << "I'm a CIRCLE:  Radius: " << radius;
    return oss.str();
  }

 private:
  double radius;
};
