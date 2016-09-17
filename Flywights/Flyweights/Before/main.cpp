#include <iostream>
using namespace std;

class Gazillion {
public:
  Gazillion() {
    m_value_one = s_sum / Y;
    m_value_two = s_sum % Y;
    ++s_sum;
  }

  void report() {
    cout << m_value_one << m_value_two << " ";
  }

  static int X, Y;

private:
  int m_value_one;
  int m_value_two;
  static int s_sum;
};

int Gazillion::X = 6, Gazillion::Y = 10, Gazillion::s_sum = 0;

int main () {
  Gazillion matrix[6][10];
  for ( int i = 0 ; i < Gazillion::X ; ++i ) {
    for ( int j = 0 ; j < Gazillion::Y ; ++j ) {
      matrix[i][j].report();
    }
    cout << endl;
  }
};








