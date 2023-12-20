//
// DotMatrixPrinter.h
//
// Printing interface
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class DotMatrixPrinter 
{
public:
  DotMatrixPrinter():port(""){}
  DotMatrixPrinter(string argPort):port(argPort){}
  void setPort(string argPort);
  string getPort();
  bool openPort();
  void closePort();
protected:
  ofstream outStream;
private:  
  string port;
};
