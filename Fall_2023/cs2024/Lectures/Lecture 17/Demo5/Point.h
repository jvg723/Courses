//
// CS2024 Lecture #17, Demo 5
//
// Point class
//

#include <iostream>
#include <fstream>
using namespace std;

//
// A simple class to help demonstrate smart pointers
//

class Point {
 public:
 Point(int argX,int argY):x(argX),y(argY) {}
  ~Point() {
    std::cout << "We are in Point's destructor: x = " << x << ", y = " << y << std::endl;
  }

  // Member variables ... we'll leave them public for ease of access
  int x;
  int y;
};


inline ostream &operator<<(ostream &os,Point &p)
{
  os << "(" << p.x << "," << p.y << ")";
  return os;
}
