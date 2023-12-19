//
// CS2024:  Lecture #12, Demo #5
//
// Inherited Exceptions
//

#include <iostream>

using namespace std;  //introduces namespace std

// Some miscellaneous error codes
enum {
    noErr,
    divByZero,
    badIndex
};

// General Base Exception class
class BaseException
{
public:
    BaseException(string msg,int err=0):message(msg),errorCode(err){}
    virtual string getMessage()
    {
	return "BASE EXCEPTION: " + message;
    }
    int getErrorCode()
    {
	return errorCode;
    }
protected:
    string message;
    int errorCode;
};

// Specific exception class for dealing with index problems
class ArrayIndexException : public BaseException
{
public:
    ArrayIndexException(string msg,int err,int index):
        BaseException(msg,err),badIndex(index){}

    string getMessage()
    {
      return "ARRAY INDEX EXCEPTION: " + message;
    }
		
    int getBadIndex()
    {
	return badIndex;
    }

private:
    int badIndex;
};


// A VERY simple integer array which does range checking
// This is an example of a TEMPLATE CLASS which we will cover
// in Lecture #19
template<int storageSize>
class MyIntArray
	{
	public:
		int &operator[](int i);
	private:
		int arrayValues[storageSize];
	};

template<int storageSize>
int &MyIntArray<storageSize>::operator[](int i)
{
	if ((i < 0) || (i >= storageSize))
		throw ArrayIndexException("Invalid index encountered",badIndex,i);
	return arrayValues[i];
}


// A simple divide operation which catches div by 0
float divide(int arg1,int arg2)
{
	if (arg2 == 0)
		throw BaseException("Divide by zero detected",divByZero);
    
	return arg1/arg2;
}

int main()
{	
    MyIntArray<5> anIntArray;
    for (int i=0; i< 5; i++)
		anIntArray[i] = i;
	
    try
    {
        cout << "5/0 = " << divide(5,0) << endl;
	cout << "anIntArray[45] = " << anIntArray[45] << endl;
    }
    
    //catch (BaseException e)
    //catch (BaseException &e)
    catch (ArrayIndexException e)
    {
		cout << e.getMessage() << ", error code: "
		     << e.getErrorCode() << 
		   ", bad index: " << e.getBadIndex() << 
		  endl;
    }
    catch(...)
    {
		cout << "Catch-all caught..." << endl;
    }
	return 0;
}

