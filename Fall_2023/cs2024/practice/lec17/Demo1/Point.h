//
// CS2024 Lecture #17, Demo 1
//
// Point class
//

#include <iostream>
#include <fstream>
using namespace std;

//
// A simple class to help demonstrate smart pointers
//

class Point
{
    public:
        Point(int argX, int argY):x(argX),y(argY) {}
        ~Point()
        {
            cout << "We are in the Point's destructor: x = " << x << ", y = " << y << endl;
        }

        // Member variables
        int x;
        int y;
};

inline ostream &operator<<(ostream &os, Point &p)
{
    os << "(" << p.x << "," << p.y << ")";
    return os;
}