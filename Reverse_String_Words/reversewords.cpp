/*
Given a string of words delimited by spaces, reverse the words in string. For example, given "hello world here", return "here world hello"

Follow-up: given a mutable string representation, can you perform this operation in-place?
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

#define pb push_back

string ReverseWords(string s) {
  vector<string> words;
  istringstream in(s);
  string word;

  while (in >> word) {
    words.pb(word);
  }

  reverse(words.begin(), words.end());
  string ret = "";

  for (string w : words) {
    ret += (w + ' ');
  }

  return ret;
}

string ReverseWordsInPlace(string s) {
  reverse(s.begin(), s.end());
  int last_word = 0;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ') {
      reverse(s.begin() + last_word, s.begin() + i);
      last_word = i + 1;
    }
  }

  reverse(s.begin() + last_word, s.end());

  return s;
}

int main() {
  cout << ReverseWords("hello world here") << endl;
  cout << ReverseWords("hello") << endl;
  cout << ReverseWordsInPlace("hello world there in") << endl;
  cout << ReverseWordsInPlace("hello i") << endl;

  return 0;
}