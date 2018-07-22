/*
Gray code is a binary code where each successive value differ in only one bit, as well as when wrapping around. Gray code is common in hardware so that we don't see temporary spurious values during transitions.

Given a number of bits n, generate a possible gray code for it.

For example, for n = 2, one gray code would be [00, 01, 11, 10].
*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

vector<string> GenerateCode(int n) {
  string start(n, '0');
  unordered_set<string> visited;
  vector<string> ret;
  queue<string> q;
  ret.push_back(start);
  visited.insert(start);
  q.push(start);

  while (!q.empty()) {
    string visited_string = q.front();
    q.pop();
    string new_string = visited_string;

    for (int i = 0; i < n; i++) {
      if (visited_string[i] == '1') {
        new_string[i] = '0';

        if (visited.find(new_string) == visited.end()) {
          ret.push_back(new_string);
          visited.insert(new_string);
          q.push(new_string);
        }
      } else {
        new_string[i] = '1';

        if (visited.find(new_string) == visited.end()) {
          ret.push_back(new_string);
          visited.insert(new_string);
          q.push(new_string);
        }
      }
    }
  }

  return ret;
}

int main() {
  vector<string> code = GenerateCode(10);
  for (string s : code) {
    cout << s << endl;
  }

  return 0;
}