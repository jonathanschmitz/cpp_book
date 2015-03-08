// init.cpp -- type changes on initialization
#include <iostream>
int main()
{
  using namespace std;
  cout.setf(ios_base::fixed, ios_base::floatfield);
  float tree = 3;  // int to float
  int guess(3.9832); // double to int
  int debt = 7.2E12; // " not defined
  cout << "tree = " << tree << endl;
  cout << "guess = " << guess << endl;
  cout << "debt = " << debt << endl;
  return 0;
}
f
