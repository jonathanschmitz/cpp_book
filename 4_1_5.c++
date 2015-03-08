#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>

using std::vector; using std::string; using std::sort; using std::streamsize;
using std::cout; using std::cin; using std::endl; using std::domain_error;
using std::setprecision; using std::istream; using std::max;

// compute the median of a vector<double>
// note that this function copies the entire argument vector
double median(vector<double> vec)
{
  typedef vector<double>::size_type vec_sz;

  const vec_sz size = vec.size();
  const vec_sz mid = size / 2;

  if (size == 0)
    throw domain_error("median of an empty vector");
  sort(vec.begin(), vec.end());

  return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

// compute a student's overall grade from midterm and final exam
// grades and homework grade median
double grade(double midterm, double final, double homework)
{
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because median does so for us
double grade(double midterm, double final, const vector<double>& hw)
{
  if (hw.size() == 0)
    throw domain_error("student has done no homework");
  return grade(midterm, final, median(hw));
}

// read homework grades from an input stream into a vector<double>
istream& read_hw(istream& in, vector<double>& hw)
{
  if (in) {
    // get rid of previous contents
    hw.clear();

    //read homework grades
    double x;
    while (in >> x)
      hw.push_back(x);

    //clear the stream so that input will work for the next student
    in.clear();
  }
  return in;
}

struct Student_info {
  string name;
  double midterm,final;
  vector<double> homework;
}; // semicolon is required

bool compare(const Student_info& A, const Student_info& B){
  return A.name < B.name;
}

int main()
{
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;

  // read and store all the records, and find the length of the longest name
  while (read(cin, record)) {
    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }

  // alphabetize the records
  sort(students.begin(), students.end(), compare);

  for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
    // write the name, padded on the right to maxlen + 1 characters
    cout << students[i].name 
	 << string(maxlen + 1 - students[i].name.size(), ' ');

    // compute and write the final grade
    try {
      double final_grade = grade(studnets[i]);
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade 
	   << setprecision(prec) << endl;
    } catch (domain_error e) {
      cout << e.what();
    }
    cout << endl;
  }
  return 0;
}

