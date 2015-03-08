// modulus.cpp -- using the modulus operator
#include <iostream>
int main()
{
  using namespace std;
  int lbs,stones, pounds;
  const int Lbs_per_stone = 14;
  
  cout << "Please enter your weight in pounds: ";
  cin >> lbs;
  stones = lbs / Lbs_per_stone;
  pounds = lbs % Lbs_per_stone;
  cout << "Your weight is " << stones << " stone and " << pounds << " pounds.\n";
  return 0;
}
