//
// CS2024 -- Lecture #16, Demo #2
//
// basic lambda expression
//

#include <iostream>

using namespace std;

int main(int argc,char *argv[])
{
  // Create an old style function pointer to store our lambda
  void (*func)(string) = [](string arg) { cout << "Hello " << arg << endl; };
  func("Ron");

  // Utilize the auto keyword to declare a variable that has a lambda assigned to it
  auto func2 = []() { cout << "Hello World!" << endl; };
  func2();

  // Use the C++11 std::function template class to specify a function pointer
  std::function<void(string)> func3 = [](string arg) { cout << "Hello " << arg << endl; };

  func3(", Goodbye");
}
