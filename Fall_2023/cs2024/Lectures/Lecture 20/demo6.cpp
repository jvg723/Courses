//
// CS2024 -- Lecture #20, Demo #6
//
// updating random access files
//

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc,char *argv[]) 
{
  int recordNumber = 0;

  // Prompt the user for the record they want to retrieve
  cout << "What record number do you want to change the age of? ";
  cin >> recordNumber;

  if (recordNumber < 0) {
    cout << "Error, invalid record number" << endl;
    return -1;
  }

  // Create an fstream variable, open file ages.dat for reading
  // and writing
  fstream file("ages.dat",ios::in |ios::out); // what is this syntax?

  // Make sure file was opened
  if (file) {
      // We must advance to the appropriate record.   
      // Record size in ages.dat is as follows:
      // 20 bytes for name, + newline at end
      //  3 bytes for age, + newline at end
      // 10 bytes for phone, + newline at end
      // Record size = 20 + 3 + 10 + newlines(3) = 36

      // We're going to be changing the age, so add 21
      // to the calculated start of record to get to the Age
      // field
    int offset = (36 * recordNumber) + 21;

      // Advance to the correct offset in the file
      file.seekp(offset);

      // We wouldn't get an error bit set if we seek too far
      // so see if the next character is -1. 
      //      if (file.peek() == -1) {
      //cout << "Error, record doesn't exist" << endl;
      //	return -1;
      //}

      // Read original age.  Note that we only called seekp() 
      // and not seekg().  This is ok.   There really is only 
      // one "read/write offset" in the file (not two separate ones)
      int originalAge;
      file >> originalAge;

      // Prompt for new age
      cout << "Enter a new age: ";
      int age;
      cin >> age;

      // ignore the newline to clear it from buffer
      // ignores the next character when no arguments
      cin.ignore();   

      // Make sure age is reasonable :-)
      if ((age > 150) || (age < 0)) {
        cout << "Error, bad age" << endl;
	return -1;
      }

      // Ask user if they really want to update
      cout << "Update age from " << originalAge << " to " << age << " ? <y/n> ";
      char c;
      cin.get(c);
     
      // Only update if they said 'y'
      if (c != 'y') {
	cout << "Update canceled." << endl;
	return -1;
      }

      // Reset seek offset
      file.seekp(offset);
       
      // Update the age!
      if (age < 10) 
	file << age << "  ";  // overwrite single digit age with two padding spaces
      else if (age < 100)
        file << age << " ";   // overwrite double digit age with one padding space
      else 
        file << age;          // overwrite three digit age
  }
   
  // Explicitly close file (though it would close when 
  // destructor was executed)
  file.close();
}
