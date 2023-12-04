//
// CS2024 Lecture #12, Demo 6
//
// bad_alloc
//

#include <iostream>
using namespace std;

int main(int argc,char *argv[])
{
  try {
    double *d = new double[1000000000000000];
    cout << "Allocated memory!" << endl;
  } catch (bad_alloc e) {
    cout << "Caught bad_alloc" << endl;
  }

  double *d = new(nothrow) double[100000000000000];
  if (d == NULL) {
    cout << "Memory allocation failed!" << endl;
  } else {
    cout << "d is " << d << endl;
  }
}
