//
// CS2024 -- Lecture #20, Demo #4
//
// reading from files
//

#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char *argv[])
{
    int recordNumber = 0;

    // Prompt the user for the record they want to retrieve
    cout << "What record number do you want? ";
    cin >> recordNumber;

    if (recordNumber < 0){
        cout << "Error, invaid record number" <<endl;
        return -1;
    }

    // Create an ifstream variable, open file ages.dat for reading
    ifstream in("ages.dat");

    // Make sure file was opened
    if (in){
        // We must advance to the appropriate record.   
        // Record size in ages.dat is as follows:
        // 20 bytes for name, + newline at end
        //  3 bytes for age, + newline at end
        // 10 bytes for phone, + newline at end
        // Record size = 20 + 3 + 10 + newlines(3) = 36

        int offset = 36 * recordNumber;

        // Advance to the correct offset in the file
        in.seekg(offset);

        if (!in){
            // something bad happened
            cout << "Error attempting to seek position" << offset << endl;
            return 0;
        }

        // This is how you'd use it to read into a C-style string
        char buffer[80];
        in.getline(buffer,80);

        if (!in){
            cout << "seek error" << endl;
            return -1;
        }

        cout << "Name: " << buffer << endl;

        in.getline(buffer,80);
        cout << "Age: " << buffer << endl;

        in.getline(buffer,80);
        cout << "Phone: " << buffer << endl;

        }

    // Explicitly close file (though it would close when 
    // destructor was executed)
    in.close();
}