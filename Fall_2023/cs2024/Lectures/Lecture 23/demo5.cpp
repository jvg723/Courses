//
// CS20204 -- Lecture #23, Demo #5
//

#include <iostream>
using namespace std;

class B {
public:
  virtual void f() { cout << "She loves me!!!!" << endl; }
};

class D1 : virtual public B {
public:
  void g() { f(); }
};

class D2 : virtual public B {
public:
  void f() { cout << "She loves me not" << endl; }
};

class DD: public D1, public D2 { };

int main()
{
  DD me;
  me.g();
}
