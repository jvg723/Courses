//
// CS2024 -- Lecture #9, Demo 4
//
// Copy Constructors
//
// WARNING:  If the copy constructor's argument is not declared as pass-by-reference,
//           we'll get a compilation error
//
#include <iostream>

using namespace std;  //introduces namespace std

class Point
{
    public:
            Point():x(0),y(0){}         // Default constructor
            Point(int thisX, int thisY):x(thisX),y(thisY){} // custom constructor
            Point(Point anotherPoint);  // copy construcotr (arg needs to be pass by reference or compilation will fail)
            int getX() { return x; }
            int getY() { return y; }

            // a getter for our private data
            void getXY(int &curX, int &curY)
            {
                curX = x;
                curY = y;
            }

            // a setter for our private data
            void setXY(int newX, int newY)
            {
                x = newX;
                y = newY;
            }

    private:
            int x,y;
};

// Here's the implementation fo the copy constructor
// Must be pass-by-reference! (will get compiler error if it is NOT)
Point::Point(Point anotherPoint)
{
    anotherPoint.getXY(x,y);

    // print out a message so we know we used the copy constructor!
    cout << "We're in a copy constructor!" << endl;
}

int main()
{
    Point p1(4,5);  // will use our custom constructor
    Point p2(p1);   // will use the copy constructor
    Point p3 = p1;  // will use the copy constructor

    // Print out data
	cout << "Point p1 is (" << p1.getX() << "," <<
	p1.getY() << ") " << endl;
	cout << "Point p2 is (" << p2.getX() << "," <<
	p2.getY() << ") " << endl;
	cout << "Point p3 is (" << p3.getX() << "," <<
	p3.getY() << ") " << endl;
	
	return 0;
    

}