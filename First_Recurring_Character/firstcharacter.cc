/*
Given a string, return the first recurring character in it, or null if there is no recurring chracter.

For example, given the string "acbbac", return "b". Given the string "abcdef", return null.
*/

#include <iostream>
#include <string>
#include <unordered_set>

char FirstRecurringCharacter(const std::string& s) {
  std::unordered_set<char> seen;

  for (char c : s) {
    if (seen.find(c) != seen.end()) {
      return c;
    }

    seen.insert(c);
  }

  return '\0';
}

int main() {
  std::cout << (FirstRecurringCharacter("acbbac") == 'b' ? 1 : 0) << std::endl;
  std::cout << (FirstRecurringCharacter("abcdef") == '\0' ? 1 : 0) << std::endl;
  
  return 0;
}