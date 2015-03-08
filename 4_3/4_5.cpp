#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cin; using std::cout; using std::endl;
using std::sort;using std::string; using std::vector;

istream& readin(istream& is, vector& words)
{
  string word;
  cin >> word;
  words.push_back(word);
  return is;
}


int main()
{
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0; // length of the longest name

  // read and store all the students name
  // Invariant: students contains all the student records so far
  // maxlen contains the length of the longest name in students
  while (read(cin, record)) {
    // find the longest name
    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }

  // alphabetize the student records
  sort(students.begin(), students.end(), compare);

  // write all the names and grades
  for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
    // write the name, padded on the right to maxlen + 1 characters
    cout << students[i].name 
	 << string(maxlen + 1 - students[i].name.size(), ' ');
    
    // compute and write the grade
    try {
      double final_grade = grade(students[i]);
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade << setprecision(prec);
    } catch (domain_error e) {
      cout << e.what();
    }
    cout << endl;
  }
  return 0;
}

