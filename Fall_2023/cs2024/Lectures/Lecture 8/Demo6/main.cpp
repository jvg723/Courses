//
// CS2024:  Lecture 8, Demo #6
//
// Demonstrate the Person class
//

#include <iostream>
#include "Person.h"

using namespace std;

int main(int argc,char *argv[]) 
{
  Person *person1 = new Person();
  Person person2("John");

  cout << "person1 is : " << person1->getName() << endl;
  cout << "person2 is : " << person2.getName() << endl;

  cout << "number of people: " << Person::numberOfPeople << endl;
  cout << "Deleting person #1" << endl;
 
  delete person1;

  cout << "number of people: " << Person::numberOfPeople << endl;
}
