//
// CS2024:  Lecture 9, Demo #1
//
// MyString.h
//
// This is the MyString string class.
//

class MyString
{
    public:
        // Constructor, now overloaded
        MyString();
        MyString(string initValue);

        // Destructor
        ~MyString();

        string MakeString();

        // Here comes the declaration for the overloaded 
        // readString member functions.
        int readString();
        int readString(int);

        // Method to return a character from internal storage
        char &charAt(int);

        // Operator overloads
        int operator~();
        string operator+();

    private:
        char *storagePtr;
        char initialStorage[32];
        int allocatedSpace;
        int stringLength;

        // helper until c++-11 comes and helps us out with construtors
        void baseInitilization();

        // Internal method used to grow storage for our string so it can
        // can store a string of the specified size
        bool growStorage(int);

        // Internal method used to tell us if the spcified index is valid
        bool isValidIndex(int index)
        {
            if ((index >= 0) && (index < stringLength))
                return true;
            else
                return false;
        }
};