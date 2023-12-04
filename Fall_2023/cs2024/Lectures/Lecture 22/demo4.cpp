//
// CS2024 -- Lecture #22, Demo 4
//
// Simple Stream I/O
//
#include <iostream>
using namespace std;

int main(int argc,char *argv[])
{
  // Let's keep reading data and echoing it until we get an EOF
  cout << "Enter some text, use EOF to terminate: " << endl;

  // NOTE:  In the PowerPoint slide I was reading into a string.   Here,
  //        I'm reading one 8-bit (1 byte) character at a time.  What
  //        happens with multi-byte characters?
  while (!cin.eof()) 
    {
      char c = cin.get();
      // Uncomment to see what's going on with emojis/multi-byte characters
      cout << "[" << int(c) << "]";
      //cout.put(c);
    }

  // peek() lets us look at the next character in the stream
  // without actually consuming it.
  cout << "Peeking at next character:  " << cin.peek() << endl;

  // What happens when we try to read after an EOF?
  cout << "Enter another character: ";
  char anotherChar;

  // This won't work because we're still in an EOF state
  cin.get(anotherChar);

  cout << "Another char is " << anotherChar << "( " << (int)anotherChar << " )" << endl;
}
