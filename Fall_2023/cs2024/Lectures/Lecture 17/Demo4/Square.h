//
// CS2024 -- Lecture #17, Demo 4
//
// Square class
//
#include <iostream>
#include <sstream>
#include "Shape.h"

class Square : public Shape 
{
 public:
  Square() {
    side = 0;
  }

  Square(double side) {
    this->side = side;
  }

  ~Square() {
    std::cout << "In Square Destructor"<< std::endl;
  }

  void setDimensions(double side) {
    this->side = side;
  }

      virtual double area() 
   {
    return side * side;
   }
  
  virtual std::string dimensions()
  {
    std::ostringstream oss;

    oss << "I'm a SQUARE:  Side: " << side;
    return oss.str();
  }
  
 private:
  double side;
};
