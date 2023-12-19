//
// CS2024 -- Lecture #11, Demo 1
//
// main.cpp
//

#include <iostream>

#include "Shape.h"

using namespace std;

// Introduce #define -- allows us to assign a literal value to a symbol
#define MAX_SHAPES 10

int main(int argc, char *argv[])
{
    Shape *shapeArray[MAX_SHAPES];
    int shapeCount = 0;

    // Allocate shapes for our array
    for (int i=0; i<MAX_SHAPES; i++)
    {
        cout << "Data for Shape #" << i << endl;
        cout << " Dimensions are: " << shapeArray[i]->dimensions() << endl;
        cout << " Area is: " << shapeArray[i]->area() << endl;
    }

    // Clean up
    for (int i=0; i<shapeCount; i++)
    delete shapeArray[i];
}