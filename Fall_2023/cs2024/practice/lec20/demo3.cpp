//
// CS2024 -- Lecture #20, Demo #3
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

    // Make sure file was opened
    if (in){
        // use eof() to let us know if we've reached the file's end
        while (!in.eof()){
            // Use getline to read a line of text from file
            // Remember that if we used operator>>, we'd stop on whitespace and not
            // (necessarily) on a newline

            // This is how you'd use it to read into a C-style string
            char buffer[80];
            in.getline(buffer,80);

            // And this is how you'd use it to read into a C++ style string
            string str;
            getline(in, str);

            // output line of text read in to cout
            cout << buffer << endl;
            cout << str << endl;
        }
    }

    // Explicitly close file (though it would close when 
    // destructor was executed)
    in.close();
}