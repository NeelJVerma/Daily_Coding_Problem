/*
Given a string, determine whether any permutation of it is a palindrome.

For example, carrace should return true, since it can be rearranged to form racecar, which is a palindrome. daily should return false, since there's no rearrangement that can form a palindrome.
*/

#include <iostream>
#include <string>
#include <cstring>

const int kMaxChars = 256;

bool IsPermOfPalindrome(const std::string& s) {
  int frequencies[kMaxChars];
  memset(frequencies, 0, sizeof(int) * kMaxChars);

  for (char c : s) {
    frequencies[int(c)]++;
  }

  int odd_occurences = 0;

  for (int i : frequencies) {
    if (i & 1) {
      odd_occurences++;
    }
  }

  if (odd_occurences == 1 & s.length() & 1) {
    return true;
  }

  if (!odd_occurences && !(s.length() & 1)) {
    return true;
  }

  return false;
}

int main() {
  std::cout << (!IsPermOfPalindrome("code") ? 1 : 0) << std::endl;
  std::cout << (IsPermOfPalindrome("carrace") ? 1 : 0) << std::endl;
  std::cout << (IsPermOfPalindrome("aab") ? 1 : 0) << std::endl;
  std::cout << (!IsPermOfPalindrome("aaba") ? 1 : 0) << std::endl;
  std::cout << (IsPermOfPalindrome("abab") ? 1 : 0) << std::endl;

  return 0;
}