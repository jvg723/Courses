//
// Printer.h
//
// Printing interface
//

#include <iostream>
#include <vector>
using std::string;
using std::vector;

class DataPrinter
{
public:
  virtual void printData(string *,int)=0;
  virtual void printData(vector<string>)=0;
};
