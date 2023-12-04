//
// CS2024 -- Lecture #15, Demo #1
//
// Nested classes
//

#include <iostream>

class A
{
public:
  void whoAmI()
  {
    std::cout << "I'm class A" << std::endl;
  }

  class B
  {
  public:
    void whoAmI()
    {
      std::cout << "I'm class B" << std::endl;
    }

  };
};

int main(int argc,char *argv[])
{
  A classA;
  A::B classB;

  classA.whoAmI();
  classB.whoAmI();

  // You cannot try to access B directly;  uncomment lines
  // below to see the error that is produced if you try
  //B anotherB;
  //anotherB.whoAmI();
}
