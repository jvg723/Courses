//
// CS2024 -- Lecture #17, Demo 3
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

  ~Circle() {
    std::cout << "In Circle Destructor" << std::endl;
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
