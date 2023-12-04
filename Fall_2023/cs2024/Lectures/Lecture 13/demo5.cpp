//
// CS2024:  Lecture #13
//
// Demo #5 -- Searching/Sorting and Range-based for loops
//

#include <iostream>
#include <array>
#include <algorithm>  // need this to have access to sort and binary_search

using namespace std;

int main(int argc, char *argv[]) 
{
  // Declare an aribitrary array
  array<int,10> someArray{8,3,6,2,5,1,4,10,9,7};

  // Use a range-based loop to print out array
  cout << "Our array looks like this initially:" << endl;
  for(int item : someArray)
    cout << item << endl;

  // Now, let's sort the array
  sort(someArray.begin(),someArray.end());

  // And print the array out again:
  cout << "\n\nOur array looks like this after sorting:" << endl;
  for(int item : someArray)
    cout << item << endl;

  // Now, ask the user to enter an element to search fo
  int someItem;
  cout << "Enter a value you want to search for: ";
  cin >> someItem;

  // search
  bool isFound = binary_search(someArray.begin(),someArray.end(),someItem);

  // inform user
  if (isFound)
    cout << someItem << " was FOUND in our array " << endl;
  else
    cout << someItem << " was NOT FOUND in our array " << endl;
}
