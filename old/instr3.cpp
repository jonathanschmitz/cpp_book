// instr3.cpp -- reading more than one word with get() & get()
#include <iostream>
int main()
{
  using namespace std;
  const int ArSize = 20;
  char name[ArSize];
  char dessert[ArSize];
  
  cout << "Enter your name:\n";
  cin.get(name, ArSize).get();  // read string, newline
  cout << "Enter your favourite dessert:\n";
  cin.get(dessert, ArSize).get();
  cout << "I have some delicious " << dessert;
  cout << " for you, " << name << ".\n";
  return 0;
}

/* 
Example run:
  Enter your name:
  Arsch Gesicht abasdfasdf
  Enter your favourite dessert:
  have some delicious asdf for you, Arsch Gesicht abasd.

=> .get(var, bytes) takes only $bytes as input, 1 per default
use: check if complete input was put into array by reading next char
*/ 


