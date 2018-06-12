/*
Given two strings A and B, return whether or not A can be shifted some number of times to get B.

For example, if A is abcde and B is cdeab, return true. If A is abc and B is acb, return false.
*/

#include <iostream>
#include <string>
using namespace std;

bool CanShift(string a, string b) {
  if (a.length() != b.length()) {
    return false;
  }

  int a_idx = 0;

  for (int i = 0; i < a.length(); i++) {
    if (a[i] == b[0]) {
      a_idx = i;
    }
  }

  for (int i = 0; i < b.length(); i++) {
    if (a[a_idx] != b[i]) {
      return false;
    }

    if (a_idx == a.length() - 1) {
      a_idx = -1;
    }

    a_idx++;
  }

  return true;
}

int main() {
  cout << (CanShift("abcde", "cdeab") ? 1 : 0) << endl;
  cout << (!CanShift("abc", "acb") ? 1 : 0) << endl;
  cout << (CanShift("a", "a") ? 1 : 0) << endl;
  cout << (!CanShift("a", "b") ? 1 : 0) << endl;
  cout << (!CanShift("abcde", "cdeabc") ? 1 : 0) << endl;
  cout << (CanShift("ab", "ba") ? 1 : 0)<< endl;

  return 0;
}