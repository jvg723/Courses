//
// CS2024 -- Lecture #20, Demo #1
//
// Simple output file
//
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc,char *argv[])
{
  // Declare a new ofstream variable with a file name
  // of "myFile.txt" and open it for writing
  ofstream out("myFile.txt",ios::out);

  // Check to see if we actually opened a file and
  // it is ready to write
  if (out.is_open()) {
    cout << "File is open, writing text..." << endl;
    // Write "Hello world!"
    out << "Hello world!" << endl;
  }

  cout << "All done!" << endl;
  // File will close when "out" goes out of scope
  return 0;
}
