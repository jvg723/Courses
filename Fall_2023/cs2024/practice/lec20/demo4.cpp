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
    // Create an ifstream variable, open file myFile.txt for reading
    ifstream in("mFile.txt",ios::in);

    // An arbitrary flag variable (bool).  We'll use this in the loop
    bool flag = false;

    // Make sure file was opened
    if (in){
        // use eof() to let us know if we've reached the file's end
        while (!in.eof()){
            cout << "in.tellg is: " << in.tellg() << endl;
            // This is how you'd use it to read into a C-style string
            char buffer[80];
            in.getline(buffer,80);

            // Purely arbitrary use of the flag variable.   It will be false the
            // first time through the loop so we'll execute this code once.  Then
            // it gets set to true and we'll never execute this code again!
            if (!flag){
                in.seekg(10);
                flag = true;
            }

            // output line of text read in to cout
            cout << buffer << endl;
        }
    }

    // Explicitly close file (though it would close when 
    // destructor was executed)
    in.close();
}