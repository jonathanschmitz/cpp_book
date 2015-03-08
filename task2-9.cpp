#include <iostream>

using std::cout; using std::cin; using std::endl;

int main()
{
  int numA;
  int numB;
  cout << "Please enter a number: ";
  cin >> numA;
  cout << "Please enter another number: ";
  cin >> numB;
  cout << (numA > numB ? numA : numB) << " is bigger.\n";
  return 0;
}
