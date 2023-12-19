//
// CS2024 -- Lecture #11, Demo 1
//
// Shape base class
//
#include <iostream>

using namespace std;

class Shape
{
    public: 
        double area ()
        {
            cout << " I have no idea what my area is!!!" << endl;
            return 0; // meaningless, we have no idea how to calculate the area
        }

        string dimensions()
        {
            string returnVal = "I have no idea what my dimensions are";
            return returnVal;
        }
};

