//
// CS2024 Lecture #16, Demo #3
//
// Specialization
//

#include <iostream>

using namespace std;  //introduces namespace std

#include "MyString.h"

// A generic template to compare to parameters of the same type
template<class aType> bool isLessThan(aType arg1,aType arg2)
{
	return arg1 < arg2;
}

// Handle the special case of character pointers
// (UNCOMMENT FOR PROPER BEHAVIOR)

bool isLessThan(char *str1,char *str2)
{  
  cout << "Specialized version is being called " << endl;
	return (strcmp(str1,str2) < 0);
}

int main()
{	
    MyString str1("Test1");
    MyString str2("Test2");
    
    // Show that template work with MyString class
    if (isLessThan(str1,str2))
		cout << str1 << " is less than " << str2 << endl;
    else
		cout << str1 << " is greater than " << str2 << endl;
	
	
    // How about char * types?
    char *cstr1,*cstr2;
	
    cstr1 = new(nothrow) char[50];
    cstr2 = new(nothrow) char[50];
	
    if (!cstr1 || !cstr2)
    {
		cerr << "Pointer allocation failed!" << endl;
		return -1;
    }
	
    strcpy(cstr1,"def");
    strcpy(cstr2,"abc");   

    // Here's a cout that will print out the pointer memory addresses for cstr1 and cstr2
    cout << (long long) cstr1 << endl << cstr1 << endl << (long long) cstr2 << endl << cstr2 << endl;
    if (isLessThan(cstr1,cstr2))
		cout << cstr1 << " is less than " << cstr2 << endl;
    else
		cout << cstr1 << " is not less than " << cstr2 << endl;
	
    delete [] cstr1;
    delete [] cstr2;
    
	return 0;
}

