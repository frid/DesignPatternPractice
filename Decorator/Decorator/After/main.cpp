#include <iostream>
using namespace std;

class I {
public:
  virtual ~I() {};
  virtual void do_it() = 0;
};

class A : public I {
public:
  ~A() {
    cout << " A dtor" << endl;
  };

  void do_it() {
    cout << "A" << endl;
  }
};

class D: public I {
public:
  D(I *inner) {
    m_wrapper = inner;
  }

  ~D() {
    delete m_wrapper;
  }

  void do_it() {
    m_wrapper->do_it();
  }
private:
  I *m_wrapper;
};

class X: public D {
  public:
    X(I *core): D(core){}
    ~X() {
        cout << "X dtor" << "   ";
    }
    /*virtual*/
    void do_it() {
        D::do_it();
        cout << 'X';
    }
};

class Y: public D {
  public:
    Y(I *core): D(core){}
    ~Y() {
        cout << "Y dtor" << "   ";
    }
    /*virtual*/
    void do_it() {
        D::do_it();
        cout << 'Y';
    }
};

class Z: public D {
  public:
    Z(I *core): D(core){}
    ~Z() {
        cout << "Z dtor" << "   ";
    }
    /*virtual*/
    void do_it() {
        D::do_it();
        cout << 'Z';
    }
};

int main() { 
  I *anX = new X(new A);
  I *anXY = new Y(new X(new A));
  I *anXYZ = new Z(new Y(new X(new A)));
  anX->do_it();
  cout << '\n';
  anXY->do_it();
  cout << '\n';
  anXYZ->do_it();
  cout << '\n';
  delete anX;
  delete anXY;
  delete anXYZ;
}





