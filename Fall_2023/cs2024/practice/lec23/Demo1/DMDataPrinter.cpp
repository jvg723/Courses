//
// DMDataPrinter.cpp
//

#include "DMDataPrinter.h"

void DMDataPrinter::printData(string *anArray,int size)
{
    if (openPort())
    {
        outStream << "ARRAY OUTPUT: " << endl;
        for (int i=0; i<size; i++)
        {
            outStream << i << " . " << anArray[i] << endl;
        }
        closePort();
    }
}

void DMDataPrinter::printData(vector<string> stringVector)
{
    if (openPort())
    {
        outStream << "ARRAY OUTPUT: " << endl;
        for (int i=0; i<stringVector.size(); i++)
        {
            outStream << i << " . " << stringVector[i] << endl;
        }
        closePort();
    }
}