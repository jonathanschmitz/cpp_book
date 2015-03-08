#include <iostream>
#include <string>

using std::cout; using std::endl; using std::string;

int main()
{
  const string shape = "square";

  if (shape == "triangle"){
    const int rows = 5;
    const int width = rows*2 - 1;
    const int start = width/2; // index of start point
    for (int r = 0; r != rows; ++r){
      string outstr(width, ' ');
      if (r == 0){
	outstr[start] = '*';
      } else if (r == rows -1){
	outstr = string(width, '*');
      } else{
	const int index_l = start - r;
	const int index_r = start + r;
	outstr[index_l] = '*';
	outstr[index_r] = '*';
      }
      cout << outstr << endl;
    }
  } else if (shape == "rectangle") {
    const int width = 10;
    const int rows = 5;
    for (int r = 0; r != rows; ++r){
      string outstr(width, ' ');
      if (r == 0 || r == rows -1){
	outstr = string(width, '*');
      }	else {
	outstr = '*' + string(width - 2, ' ') + '*';
      }
      cout << outstr << endl;
    }
  } else if (shape == "square") {
    const int width = 10;
    for (int r = 0; r != width; ++r){
      string outstr(width, ' ');
      if (r == 0 || r == width -1)
	outstr = string(width, '*');
      else 
	outstr = '*' + string(width -2, ' ') + '*';
      cout << outstr << endl;
    }
  }
  
  return 0;
}
