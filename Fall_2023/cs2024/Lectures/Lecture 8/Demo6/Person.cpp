//
// CS2024: Lecture #8, Demo 6
//
// Person class -- Implementation
//

#include "Person.h"

// Define storage for the static member variable
int Person::numberOfPeople = 0;

// Simple constructor simply sets the name of the
// person to the default                                                                                                           
Person::Person()
{
  name = DEFAULT_NAME;
  numberOfPeople++;
}

// Constructor that takes a name as argument  
Person::Person(std::string name)
{
  // Utilize "this" to differentiate between
  // the member variable and the argument
  this->name = name;
  numberOfPeople++;
}

// Destructor needed to decrement the people count
Person::~Person()
{
  numberOfPeople--;
}

// setName allows the user to set the name
// of our Person
void Person::setName(std::string name)
{
  // Utilize "this" to differentiate between
  // the member variable and the argument
  this->name = name;
}

// getName() returns the name of the person
// Since it has no need to modify anything
// in the class, it is designated as const
std::string Person::getName() const
{
  return name;
}
