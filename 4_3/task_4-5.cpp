#include <algorithm>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::istream;
using std::sort;using std::string; using std::vector;


// read words from input stream
istream& readin(istream& is, vector<string>& words)
{
  if (is){
    string word;
    while (cin >> word){
      words.push_back(word);
    }
  }
  return is;
}



int main()
{
  vector<string> words;
  readin(cin, words);
  cout << "Number of words: " << words.size() << endl;
  vector<string> uwords;
  vector<int> word_num;
  for (int i = 0; i != words.size(); ++i){
    const string word = words[i];
    int present_index = -1;
    for (int j = 0; j != uwords.size(); ++j){
      if (word == uwords[j]){
	present_index = j;
	break;
      }
    }
    if (present_index > -1){
      ++word_num[present_index];
    } else {
      uwords.push_back(word);
      word_num.push_back(1);
    }
  }
  for (int i = 0; i != uwords.size(); ++i){
    cout << uwords[i] << "\t" << word_num[i] << endl;
  }
  return 0;
}

