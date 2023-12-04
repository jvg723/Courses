//
// CS2024 -- Lecture #20, Demo #3
//
// CS2024 Lecture #17, Demo 5
//
// Weak Pointers
//

#include <iostream>
#include <memory>

#include "Point.h"

using namespace std;

// Common to typedef the shared_ptr declaration into a simpler type name
typedef shared_ptr< Point > PointPtr;


int main(int argc,char *argv[]) {
  // Allocate a new shared pointer to our Point class
  shared_ptr< Point > pointPtr( new Point(1,2) );
  cout << "Reference count for Point: " << pointPtr.use_count() << endl;

  weak_ptr< Point > weakPointPtr = pointPtr;
  // Introduce a new scope to illustrate reference counting
  if (true) {
    PointPtr pointPtr2( pointPtr );

    // change a value in the Point class using pointPtr2 
    pointPtr2->x = 5;
    cout << "Reference count for Point: " << pointPtr.use_count() << endl;
    cout << "pointPtr2 about to go out of scope" << endl;
  }

  // pointPtr2 is now out of scope
  cout << "Reference count for Point: " << pointPtr.use_count() << endl;
  cout << "Point is now: " << *pointPtr << endl;    

  // Reset shared pointer.   What happend to weakPtr?
  pointPtr.reset();

  // Two ways to convert a weak_ptr back to a shared_ptr.
  // Both will increase the reference count on the shared_ptr by 1

  // If weakPointPtr's shared_ptr has been released, this will return NULL
  //shared_ptr< Point > pointPtr3 = weakPointPtr.lock();   

  // If weakPointPtr's shared_ptr has been released, this will throw an exception
  shared_ptr< Point > pointPtr3( weakPointPtr );
  
  // Double check what the reference count is
  //cout << "Reference count is now: " << pointPtr3.use_count() << endl;

  // If pointPtr2 evaluates to false, the original shared_ptr has been freed
  if (pointPtr3)
    cout << "weakPtr is still alive" << endl;
  else
    cout << "weakPointPtr is dead!" << endl;

  // Access data from newly created shared pointer
  // We should really make sure pointPtr2 is valid before attempting
  // to do this!
  cout << (*pointPtr3).x << endl;
}

