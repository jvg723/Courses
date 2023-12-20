//
// DMDataPrinter.h
//

#include "DotMatrixPrinter.h"
#include "DataPrinter.h"

class DMDataPrinter : public DataPrinter, public DotMatrixPrinter
{
public:
  void printData(string *,int);
  void printData(vector<string>);
};
