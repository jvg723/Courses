//
// CS2024 -- Lecture #19, Demo #2
//
// main.cpp
//

#include <iostream>
#include "SimpleIntArray.h"

int main(int argc,char *argv[])
{
  // Declare a SimpleIntArray that can hold 5 elements
  SimpleIntArray sia(5);

  // Arbirtrarily assign values to array
  sia[0] = 1;
  sia[1] = 3;
  sia[2] = 5;
  sia[3] = 7;
  sia[4] = 9;

  // Output array using overloaded operator<<
  std::cout << "sia is: " << sia << std::endl;
}

