//
// CS2024 -- Lecture #11, Demo 4
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
  virtual double area() 
  {
      std::cout << "I have no idea what my area is!!!" << std::endl;
      return 0;  // meaningless, we have no idea how to calculate the area!
  }

  virtual std::string dimensions()
  {
      return "UNKNOWN -- NO DIMENSIONS";
  }
};

#endif
