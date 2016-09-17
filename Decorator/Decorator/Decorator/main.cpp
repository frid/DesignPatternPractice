#include <iostream>
using namespace std;

class A{
public:
  virtual void do_it() {
    cout << "A" ;
  }
};

class AwithX: public A {
public:
  void do_it() {
    A::do_it();
    do_X();
  }

protected:
  void do_X() {
    cout << "X";
  }
};

class AwithY: public A {
public:
  void do_it() {
    A::do_it();
    do_Y();
  }

protected:
  void do_Y() {
    cout << "Y";
  }
};


class AwithZ : public A {
public:
  void do_it() {
    A::do_it();
    do_Z();
  }
protected:
  void do_Z() {
    cout << "Z";
  }
};

class AwithXY : public AwithX, public AwithY {
public:
  void do_it() {
    AwithX::do_it();
    AwithY::do_Y();
  }
};

class AwithXYZ: public AwithX,  public AwithY, public AwithZ {
public:
  void do_it() {
    AwithX::do_it();
    AwithY::do_Y();
    AwithZ::do_Z();
  }
};

int main(void) {
  AwithX anX;
  AwithXY anXY;
  AwithXYZ anXYZ;

  anX.do_it(); cout << endl;
  anXY.do_it(); cout << endl;
  anXYZ.do_it(); cout << endl;
}
