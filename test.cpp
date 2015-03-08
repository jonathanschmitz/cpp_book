#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main()
{
  {
    const string s = "a string";
    {
      const string x =  s + " another string";
      cout << s << endl;
      cout << x << endl;
    }
    }
  return 0;
}
