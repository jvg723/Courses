//
// MyString.h
//
// This is the MyString string class.
//
// Version 0.5
//   -- Fix minor incompatabilities with various compilers
//
#include <cstring>

class MyString
{
public:
  // Constructors
  MyString();
  MyString(string);
  MyString(MyString &aCopy);
  
  // Destructor
  virtual ~MyString();
  
  // Operator overloads
  MyString &operator=(const MyString &sourceStr);
  int operator~();
  char &operator[](int i) const;
  operator string() const;
  
  string MakeString() const;
  int MakeInt() const;
  bool setValue(string newValue);
  char *getStoragePtr() const
  {
    return storagePtr;
  }
  
  int getAllocatedSpace() 
  { 
    return allocatedSpace;
  }
  
  // Here comes the declarations for the overloaded
  // readString() member function.
  int readString();
  int readString(int maxSpace);
  
  int findChar(char c,int startPos=0,int stopPos=-1);
  char &element(int i) const;
  
  
private:
  bool growStorage(int);
  char *storagePtr;
  char initialStorage[20];
  int allocatedSpace;
  int stringLength;
};

inline bool operator==(const MyString &str1,const MyString &str2)
{
  if (!strcmp(str1.getStoragePtr(),str2.getStoragePtr()))
    return true;
  return false;
}

inline bool operator<(const MyString &str1,const MyString &str2)
{
  if (strcmp(str1.getStoragePtr(),str2.getStoragePtr()) < 0)
    return true;
  return false;
}

inline MyString operator+(const MyString &str1, const MyString &str2)
{
  MyString retStr(((string)str1)+((string)str2));
  return retStr;
}

inline ostream& operator<<(ostream &os,MyString &myStr)
{
  os << (string) myStr;
  return os;
}

inline istream& operator>>(istream &is,MyString &myStr)
{
  int allocatedSpace = myStr.getAllocatedSpace();
  char *tempBuf = new char[allocatedSpace];
  is.get(tempBuf,allocatedSpace-1);
  string tempStr = tempBuf;
  myStr.setValue(tempStr);
  delete [] tempBuf;  
  return is;
}

