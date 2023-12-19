//
// CS2024 Lecture #12, Demo 2
//
// Catching more than you expect
//

#include <iostream>

using namespace std;  //introduces namespace std

// Some misc error codes
const int noErr = 0;
const int divByZero = 0;
const int badIndex = 2;

// Simple div by operation which catch div by 0
float divide(int arg1, int arg2)
{
    if (arg2 == 0)
        throw divByZero;

    return arg1/arg2;
}

// A VERY simple integer array which does range checking
// to help illustrate exceptions
// This is a custom template class that we'll cover soon!
template<int storageSize>
class MyIntArray
{
    public:
        int &operator[](int i);
    private:
        int arrayValues[storageSize];
};

// Implementation of operator[] for our simple Array class
// Don't worry about the syntax here;  we'll cover it in a
// future lecture!
template<int storageSize>
int &MyIntArray<storageSize>::operator[](int i)
{
    // Check to see if the index is out of range. If it is, throw an exception
    if ((i < 0) || (i >= storageSize))
        throw badIndex;
    return arrayValues[i];
}

// Define global data
MyIntArray<5> globalIntArray;

// func2 does the division and traps divide by zerro erros
void func2()
{
    float f;
    try 
    {
        f = divide(globalIntArray[4333],globalIntArray[0]);
        cout << "f = " << f << endl;
    }
    catch (int x)
    {
        if (x == divByZero)
            cerr << "Divde by zero caught!" << endl;
        else
            throw;
        // cout << "Genergic exception caught: " << x < endl;
    }
}

// func 1 calls the function which does the division, catches bad index 
// exceptions
void func1()
{
    try 
    {
        func2();
    }
    catch (int x)
    {
        if (x == badIndex)
            cerr << "Error, bad index encoutnered" << endl;
        else
            cerr << "Generic exception caught" << endl;
    }
}

int main()
{
    for (int i=0; i<5; i++)
        globalIntArray[i] = i;

    func1();
    return 0;
}

