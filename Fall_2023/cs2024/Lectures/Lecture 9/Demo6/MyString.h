//
// CS2024:  Lecture 9, Demo #6
//
// MyString.h
//
// This is the MyString string class.
//

#include <string> // Required for visual studio
#include <iostream>
class MyString
{
public:
  // Constructors, now overloaded
  MyString();
  MyString(string initValue);
  MyString(MyString &aCopy);

  // Destructor
  ~MyString();

  string MakeString() const;
  bool setValue(const string newValue);
  int getAllocatedSpace();

  // Here comes the declarations for the overloaded
  // readString() member function.
  int readString();
  int readString(int);
  
  // Method to return a character from internal storage
  char &charAt(int) const;

  // Operator overloads
  MyString &operator=(const MyString &arg);
  int operator~();
  string operator+() const;

  char &operator[](int index) const;
  ostream& operator<<(ostream &os);
private:
  char *storagePtr;
  char initialStorage[32];
  int allocatedSpace;
  int stringLength;

  void baseInitialization();
  
  // Internal method used to grow storage for our string so it can
  // can store a string of the specified size
  bool growStorage(int);

  // Internal method used to tell us if the specified index is valid
  bool isValidIndex(int index)  const
  {
    if ((index >= 0) && (index < stringLength))
      return true;
    else
      return false;
  }

};


inline MyString operator+(MyString &str1,MyString &str2)
{
  MyString returnStr((+str1)+(+str2));
  return returnStr;
}

//
// This simple operator overload allows us to use MyString with cout
//

inline ostream& operator<<(ostream &os,MyString &str)
{
  // os represents whatever output stream the << operator is being
  // used with.  In most cases it will be cout, but could be for 
  // a file (down the road, in a later lecture)
  os << +str;

  // We must always return the stream that was passed in.   That allows
  // "chaining" to work (cout << "Hello " << "world " << endl;)
  return os;
}

//
// Overload the >> operator so we can read strings into a MyString
//
inline istream& operator>>(istream &is, MyString &str)
{
  // Get the amount of space allocated to the MyString
  int allocatedSpace = str.getAllocatedSpace();

  // Allocate a temporary array of char equal to the size of 
  // the space allocated to our MyString
  char *tempBuf = new char[allocatedSpace];  

  // Use the get() method associated with the istream class
  // to retrieve up to allocatedSpace characters.   We use 
  // allocatedSpace-1 to account for the null byte needed by
  // c-style strings
  is.get(tempBuf,allocatedSpace-1);  
  is.ignore(1,'\n');
  // Convert C-style string to a C++ string
  string tempStr = tempBuf;

  printf("tempStr is '%s'\n",tempBuf);
  printf("length is %ld\n",strlen(tempBuf));
  // Use C++ string to set the value of the MyString
  str.setValue(tempStr);

  // Clean up temporary memory allocated
  delete [] tempBuf;

  // Return the istream so stream chaining works
  return is;
}
