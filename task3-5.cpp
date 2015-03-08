#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <typeinfo>

using std::cout; using std::cin; using std::endl;
using std::sort; using std::vector; using std::string;

double calc_final_grade(string &);

double calc_final_grade(string &grade_str)
{
  double midterm, final, tmp, grade;
  vector<double> homeworks;
  std::istringstream grade_stream(grade_str);
  grade_stream >> midterm >> final;
  while (grade_stream >> tmp)
    homeworks.push_back(tmp);
  vector<double>::size_type num_homeworks = homeworks.size();
  vector<double>::size_type mid_index = num_homeworks / 2;
  double homework_median = num_homeworks % 2 == 0 ?
    (homeworks[mid_index - 1] + homeworks[mid_index]) / 2. : homeworks[mid_index];
  grade = 0.2 * midterm + 0.4 * final + 0.4 * homework_median;
  // cout << "Final: " << final << endl
  //      << "Midterm: " << midterm << endl
  //      << "Homework Median: " << homework_median << endl
  //      << "Final Grade: " << grade << endl;
  return grade;
}

int main()
{
  vector<string> names, grades;
  cout << "Please input student names followed by their midterm, final,"
    " and homework grades, one student per line: " << endl;
  string line;
  while (getline(cin, line)){
    int first_space = line.find(" ");
    string name = line.substr(0, first_space);
    string grades = line.substr(first_space + 1, string::npos);  // we don't need the first space
    // cout << "Name: " << name << endl;
    // cout << "Grades: " << grades << endl;
    double final_grade = calc_final_grade(grades);
    cout << final_grade << endl;
  }
}
