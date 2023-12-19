//
// CS2024 -- Lecture #11, Demo 5
//
// Shape base class
//

// "Include Guard" -- This is the first time we need them!
#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape 
{
 public:
  virtual ~Shape() { std::cout << "Destructor base class" << std::endl;};

  virtual double area() = 0;
  virtual std::string dimensions() = 0;
};

#endif
