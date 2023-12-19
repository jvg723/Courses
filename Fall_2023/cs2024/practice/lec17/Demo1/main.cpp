//
// CS2024 -- Lecture #17, Demo #1
//
// Shared Pointers
//

#include <iostream>
#include <memory>

#include "Point.h"

using namespace std;

// Common to typdef the shared_ptr declaration into a simpler name
typedef shared_ptr< Point > PointPtr;

int main(int argc, char *argv[])
{
    // Allocate a new shared pointer to our point class
    shared_ptr< Point > pointPtr( new Point(1,2) );
    cout << "Reference count for Point: " << pointPtr.use_count() << endl;
    
    cout << "x coordinate is " <<(*pointPtr).x << endl;

    // Introduce a new scope to illustrate reference couting 
    if (true)
    {
        PointPtr pointPtr2 ( pointPtr );

        // change a value in the Point class using pointPtr2
        pointPtr2->x = 5;
        cout << "Reference count for Point: " << pointPtr.use_count() << endl;
        cout << "Point is now: " << *pointPtr << endl;
    }
}