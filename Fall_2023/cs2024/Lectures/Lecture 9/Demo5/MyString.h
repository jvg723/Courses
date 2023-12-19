//
// CS2024:  Lecture 9, Demo #5
//
// MyString.h
//
// This is the MyString string class.
//

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
