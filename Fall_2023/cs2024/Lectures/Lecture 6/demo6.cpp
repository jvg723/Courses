//
// CS2024 -- Lecture #6
//
// Demo #6 -- Pointers as Parameters
//

#include <iostream>

using namespace std;

//void swap(int [], int, int);

void swap(int A[8], int j, int k)
{
	int temp = A[j];
	A[j] = A[k];
	A[k] = temp;
}

int main(int argc, char *argv[])
{
  int b[]={1,2,3,4,5,6,7,8};   
	
	cout << "b: ";
	
	// Print out the array "b"
	for (int i=0; i<8; i++)
		cout << " " << b[i];
	
	cout << endl;
    
	// Swap elements #2 and #3
	swap(b,2,3);
	cout << "b: ";
	
	// Print out the array "b" again, using alternative syntax
	for (int i=0; i<8; i++)
		cout << " " << i[b];
    
	cout << endl;
	
	// Swap elements #0 and #7
	swap(b,0,7);
	cout << "b: ";
	
	// Print out the array "b" again, using a third syntax
	for (int i=0; i<8; i++)
		cout << " " << *(b+i);
    
	cout << endl;
	
	
	return 0;
}

