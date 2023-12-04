//
// CS2024 -- Lecture #3
//
// Demo 8 : Function Overloading
//


#include <iostream>

using namespace std;

// This version handles long input types
long squareIt(long x) 
{
  cout << "[squareIt(long)]";
  return x * x;
}

long long squareIt(long long x)
{
  cout << "[squareIt(long long)]";
  return x * x;
}

double squareIt(double d)
{
  cout << "[squareIt(double)]";
  return d * d;
}


int main(int argc, char *argv[]) 
{
  double d = 3.142;
  long x = 5;


  cout << d << " squared is " << squareIt(d) << endl;

  // No more problem below;  we're not passing a type that is an exact
  // match to one of the overloaded functions
  cout << x << " squared is " << squareIt(x) << endl;
}
