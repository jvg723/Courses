//
// CS2024:  Lecture 8, Demo #1
//
// MyString.h
//
// This is the MyString string class.
//

class MyString
{
    public:
        // Constructors
        MyString();

        string MakeString();

        // Here comes the declerations for the overload
        // readString() member function.
        int readString();
        int readString(int);
        
    private:
        char *storagePtr;
        char initalStorage[32];
        int allocatedSpace;
        int stringLength;

    // Internal method used to grow storage for our string so it can
    // store a string fo the specified size
    bool growStorage(int);
};
