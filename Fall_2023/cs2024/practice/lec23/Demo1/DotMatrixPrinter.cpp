//
// DotMatrixPrinter.cpp
//

#include "DotMatrixPrinter.h"

void DotMatrixPrinter::setPort(string argPort)
{
    port = argPort;
}

string DotMatrixPrinter::getPort()
{
    return port;
}

bool DotMatrixPrinter::openPort()
{
    outStream.open(port.c_str());
    if (outStream.is_open())
    {
        outStream << "DOT MATRIX PORT IS OPEN ON: " << port.c_str() << endl;
        outStream << "=====================================================" << endl;
        return true;
    }
    return false;
}

void DotMatrixPrinter::closePort()
{
    outStream.close();
}