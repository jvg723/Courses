//
// CS2024 -- Lecture #11, Demo 6
//
// Rectangle class
//
#include <iostream>
#include <sstream>
#include "Shape.h"

class Rectangle : public Shape 
{
 public:
  Rectangle() {
    length = 0;
    width = 0;
  }

  Rectangle(double length,double width) {
    this->length = length;
    this->width = width;
  }

  ~Rectangle() {
    std::cout << "In Rectangle Destructor"<< std::endl;
  }

  void setDimensions(double length,double width) {
    this->length = length;
    this->width = width;
  }

  virtual double area() 
  {
    return length * width;
  }

  virtual std::string dimensions()
  {
    std::ostringstream oss;

    oss << "I'm a RECTANGLE:  length: " << length << ", width: " << width;
    return oss.str();
  }

 private:
  double length;
  double width;
};
