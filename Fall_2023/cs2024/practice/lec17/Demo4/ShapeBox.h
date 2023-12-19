//
// CS2024 -- Lecture #17, Demo 3
//
// ShapeBox.h
//

#include <iostream>
#include <vector>
#include <memory>

#include "Shape.h"

using namespace std;

class ShapeBox
{
    public:
            int count() { return shapes.size(); }

            // When adding a shared_ptr to the vector, we actually make a copy 
	        // of the shared_ptr to store in the vector.   So after the push_back, we'll see
	        // the use_count go up to 2.   But then the shapePtr parameter goes out of 
	        // scope at the end of the function and the use_count will drop back to 
	        // 1 when we return to main (that part is not shown)
            void addShape(shared_ptr<Shape> shapePtr) 
            {
                cout << "Adding new shape, use_cout is " << shapePtr.use_count() << endl;
                shapes.push_back(shapePtr);
                cout << "Just after push_back, use_count is " << shapePtr.use_count() << endl; 
            }
            void display ()
            {
                for (auto shape : shapes)
                {
                    cout << shape->dimensions() << endl;
                }
            }

    private:
            vector<shared_ptr<Shape>> shapes;
};