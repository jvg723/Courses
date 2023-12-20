//
// CS2024 Lecture #20, Demo #1
//
// Simple Multiple Inheritance
//

#include <iostream>

using namespace std;  //introduces namespace std

#include "DMDataPrinter.h"

int main(int argc, char *argv[])
{	
	DMDataPrinter aDataPrinter;
	string myStringArray[7];
	
	aDataPrinter.setPort("test.dat");
	
    // Arbitrarily set up an array of MyStrings
    myStringArray[0] = "We";
    myStringArray[1] = "only";
    myStringArray[2] = "have";
    myStringArray[3] = "THREE";
    myStringArray[4] = "more";
    myStringArray[5] = "lectures";
    myStringArray[6] = "left";
    
    DataPrinter *dp = &aDataPrinter;
    
    dp->printData(myStringArray,7);
    
	return 0;
}

