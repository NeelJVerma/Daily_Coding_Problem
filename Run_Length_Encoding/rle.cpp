/*
Run-length encoding is a fast and simple method of encoding strings. The basic idea is to represent repeated successive characters as a single count and character. For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".

Implement run-length encoding and decoding. You can assume the string to be encoded have no digits and consists solely of alphabetic characters. You can assume the string to be decoded is valid.
*/

#include <iostream>
#include <string>
using namespace std;

string Encode(string s) {
  string result = "";
  int counter = 1;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] != s[i + 1]) {
      result += to_string(counter) + s[i];
      counter = 1;

      continue;
    }

    counter++;
  }

  return result;
}

string Decode(string s) {
  string result = "";

  for (int i = 0; i < s.length(); i += 2) {
    string to_add(int(s[i] - '0'), s[i + 1]);
    result += to_add;
  }

  return result;
}

int main() {
  cout << Encode("AAAABBBCCDAA") << endl;
  cout << Decode(Encode("AAAABBBCCDAA")) << endl;

  cout << Encode("A") << endl;
  cout << Decode(Encode("A")) << endl;

  cout << Encode("ABCD") << endl;
  cout << Decode(Encode("ABCD")) << endl;
  
  return 0;
}