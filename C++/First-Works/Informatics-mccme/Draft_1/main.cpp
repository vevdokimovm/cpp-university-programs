#include <iostream>
using namespace std;

int foo() {
  //int * m[1];
  cout << "Hacked" << endl;
  //m[2] = m[3];
  return 2;
}

int bar() {
  int * m[1];
  //m[3] = m[2];
  m[2] = (int *) &foo;

  return 1;
}

int main()
{
  bar();
  cout << "Affirmative";
  return 0;
}
