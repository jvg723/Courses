//
// CS2024:  Lecture #8, Demo 6
//
// Simple Person Class
//

#include <iostream>

class Person
{
public:
  // Simple constructor simply sets the name of the 
  // person to the default
  Person();

  // Constructor that takes a name as argument
  Person(std::string name);

  // Destructor needed to decrement the people count
  ~Person();

  // setName allows the user to set the name
  // of our Person
  void setName(std::string name);

  // getName() returns the name of the person
  // Since it has no need to modify anything
  // in the class, it is designated as const
  std::string getName() const;

  // Declare a static counter to keep track of how 
  // many People there are!
  static int numberOfPeople;

 private:
  // store the name of our Person
  std::string name;

};
 
// define the default name.  It never needs
// to change so it is marked as const.  Technically, defining
// a global variable for this purpose isn't the best solution.
// In C++11 there's a way we can put this in the class definition.
const std::string DEFAULT_NAME = "Ron";
