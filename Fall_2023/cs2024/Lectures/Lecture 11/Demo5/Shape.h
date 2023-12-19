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
  virtual double area() { std::cout << "I don't know" << std::endl; return 0;}// = 0;
  virtual std::string dimensions() { std::cout<< "I don't know" << std::endl;
    return "I don't know";}// = 0;
};

#endif
