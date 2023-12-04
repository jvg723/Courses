//
// CS2024 -- Lecture #20, Demo #2
//
// Using default arguments to ofstream constructor
// Treating stream variable as boolean
//
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc,char *argv[])
{
  // Declare a new ofstream variable with a file name
  // of "myFile.txt" and open it for writing
  // Don't need to specify ios::out;  it is the default
  ofstream out("myFile2.txt");

  // Check to see if we actually opened a file and
  // it is ready to write.   We can just check the boolean
  // value of the ofstream variable -- it will be 
  // false if the file could not be opened
  if (out) {
    cout << "File is open, writing text..." << endl;
    // Write "Hello world!"
    out << "Hello world!" << endl;
  } else {
    cout << "Could not open file myFile2.txt" << endl;
  }

  // Now open original file (from Demo #1) with the "append" mode
  ofstream out2("myFile.txt",ios::app);
  if (out2) {
    // Append to original file from demo #1
    cout << "Appending..." << endl;
    out2 << "What a nice day it is!" << endl;
  } else {
    cout << "Could not open file myFile.txt for append" << endl;
  }

  cout << "All done!" << endl;
  // File will close when "out" goes out of scope
  return 0;
}
