#include <iostream>
#include <algorithm>
#include <vector>

using std::cout; using std::cin; using std::endl;
using std::sort; using std::vector;

int main()
{
  vector<int> v;
  v.push_back(13);
  for (int i = 1; i != 47; ++i){
    v.push_back(i);
  }
  sort(v.begin(), v.end());
  typedef vector<double>::size_type vec_sz;
  vec_sz size = v.size();
  vec_sz mid = size/2.;
  cout << size << " " << v.size() << endl;
  int q1end = (mid/2) + 1, q2end = mid + 1, q3end = (mid + mid / 2) + 1;
  if (mid % 2 != 0)
    cout << "incrementing" << endl;
    q3end++;
  vector<int> q1, q2, q3, q4;
  for (int i = 0; i != q1end; ++i){
    q1.push_back(v[i]);
  }
  for (int i = q1end; i != q2end; ++i){
    q2.push_back(v[i]);
  }
  for (int i = q2end; i != q3end; ++i){
    q3.push_back(v[i]);
  }
  for (int i = q3end; i != size; ++i){
    q4.push_back(v[i]);
  }

  cout << "Q1: ";
  for (int i = 0; i != q1.size(); ++i){
    cout << q1[i] << " ";
  }
  cout << endl;
  cout << "Q2: ";
  for (int i = 0; i != q2.size(); ++i){
    cout << q2[i] << " ";
  }
  cout << endl;
  cout << "Q3: ";
  for (int i = 0; i != q3.size(); ++i){
    cout << q3[i] << " ";
  }
  cout << endl;
  cout << "Q4: ";
  for (int i = 0; i != q4.size(); ++i){
    cout << q4[i] << " ";
  }
  cout << endl;
  return 0;
}

