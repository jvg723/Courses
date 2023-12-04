//
// CS2024 -- Lecture #17, Demo 3
//
// Ellipse class
//
#include <iostream>
#include <sstream>
#include "Shape.h"

class Ellipse : public Shape 
{
 public:
  Ellipse() {
    major_radius = 0;
    minor_radius = 0;
  }

  Ellipse(double major, double minor) {
    major_radius = major;
    minor_radius = minor;
  }

  ~Ellipse() {
    std::cout << "In Ellipse Destructor"<< std::endl;
  }

  void setDimensions(double major, double minor) {
    major_radius = major;
    minor_radius = minor;
  }

  virtual double area() 
  {
    return 3.14 * major_radius * minor_radius;
  }

  virtual std::string dimensions()
  {
    std::ostringstream oss;

    oss << "I'm an ELLIPSE:  Major Radius: " << major_radius << ", Minor Radius: " << minor_radius;
    return oss.str();
  }

 private:
  double major_radius;
  double minor_radius;
};
