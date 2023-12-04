//
// CS2024 -- Demo #1, Lecture #13
//
// auto in C++11
//
// WARNING:  Code will not compile as is, see comment below
//

#include <iostream>

int main(int argc,char *argv[])
{
  auto x = 1;
  auto flag = true;
  auto str = "Hello World!";

  std::cout << "x is an int with value: " << x << std::endl;
  std::cout << "flag is a boolean with value: " << flag << std::endl;

  // You may think that str is a C++ string but it's not!
  // So the line below will not work  (Comment it out to allow code to compiler)
  std::cout << "str length is: " << str.length() << std::endl;

  // A string literal in your source code is actually a C-style string
  // with a type of "const char *".   So, you'd have to use strlen() to
  // get the length of what is in "str"
  std::cout << "str length is: " << strlen(str) << std::endl;
}
