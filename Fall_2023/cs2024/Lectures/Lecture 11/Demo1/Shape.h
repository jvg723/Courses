//
// CS2024 -- Lecture #11, Demo 1
//
// Shape base class
//
#include <iostream>

class Shape 
{
 public:
  double area() 
  {
    std::cout << "I have no idea what my area is!!!" << std::endl;
    return 0;  // meaningless, we have no idea how to calculate the area!
  }

  std::string dimensions()
  {
    std::string returnVal = "I have no idea what my dimensions are";
    return returnVal;
  }
};
