// 
// CS 2024 -- Lecture #3
// 
// Demo #8: function overloading

#include <iostream>
using namespace std;

// This version handles long input types
long squareIs(long x)
{
    cout << "[squareIt(long)]";
    return x * x;
}

long long squareIs(long long x)
{
    cout << "[squareIt(long long)]";
    return x * x;
}

double squareIt(double d)
{
    cout << "[squareIt(double)]";
    return d * d;
}

int main (int argc, char * argv[])
{
    double d = 3.142;
    int x = 5; 

    cout << d << "squared is" << squareIt(d) << endl;

    // Problem below: compiler doesn't know which overloaded function to use
    cout << x << " squared is " << squareIt(x) << endl;
}

