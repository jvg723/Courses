//
// CS2024 -- Lecture #3
//
// Demo #1: Factorial Function (for small numbers)
//

#include <iostream>
using namespace std;  

long factorial(int);

// Here's main, where we call factorial()
int main(int argc, char *argv[])
{	
	int x;
	cout << "Please enter a number> ";
	cin >> x;
	cout << x << "! is " << factorial(x) << endl;
	return 0;
}


// Here's the factorial function
long factorial(int n)
{
  long result=1;  
  for (int k=n; k > 1; k--)
  {
	result *= k; 
  }
  return result;
}
