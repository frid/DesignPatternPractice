#include <iostream>
#include <string>
using namespace std;

class Subject {
public:
  virtual void execute() = 0;
};

class RealSubject: public Subject {
  string str;
public:
  RealSubject(string s) {
    str = s;
  }

  void execute() {
    cout << str << endl;
  }
};

class ProxySubject: public Subject {
  string first, second, third;
  RealSubject *ptr;
public:
  ProxySubject(string s) {
    int num = s.find_first_of(" ");
    first = s.substr(0, num);
    s = s.substr(num+1);
    num = s.find_first_of(" ");
    second = s.substr(0, num);
    s = s.substr(num+1);
    num = s.find_first_of(" ");
    third = s.substr(0, num);
    s = s.substr(num+1);
    ptr = new RealSubject(s);
  }

  ~ProxySubject() {
    delete ptr;
  }

  RealSubject *operator->() {
    cout << first << " " << second << " ";
    return ptr;
  }

  void execute() {
    cout << first << " " << third << " ";
    ptr->execute();
  }
};

int main() {
  ProxySubject obj(string("the quick brown fox jumped over the dog"));
  obj->execute();
  obj.execute();
  return 0;
}