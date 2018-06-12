/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example, given [100, 4, 200, 1, 3, 2], the longest consecutive element sequence is [1, 2, 3, 4]. Return its length: 4.
*/

#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

int LongestConsecutiveSubsequence(int* arr, int size) {
  unordered_set<int> seen;

  for (int i = 0; i < size; i++) {
    seen.insert(arr[i]);
  }

  int longest = 0;

  for (int num : seen) {
    if (seen.find(num - 1) == seen.end()) {
      int inc = 1;
      int arr_inc = num + 1;

      while (seen.find(arr_inc) != seen.end()) {
        arr_inc++;
        inc++;
      }

      longest = max(longest, inc);
    }
  }

  return longest;
}

int main() {
  int arr_1[] = { 100, 4, 200, 1, 3, 2 };
  cout << (LongestConsecutiveSubsequence(arr_1, 6) == 4 ? 1 : 0) << endl;

  int arr_2[] = { 1, 5, 2, 3, 6, 4 };
  cout << (LongestConsecutiveSubsequence(arr_2, 6) == 6 ? 1 : 0) << endl;

  int arr_3[] = { 1 };
  cout << (LongestConsecutiveSubsequence(arr_3, 1) == 1 ? 1 : 0) << endl;

  int arr_4[] = { 2, 4 };
  cout << (LongestConsecutiveSubsequence(arr_4, 2) == 1 ? 1 : 0) << endl;

  int arr_5[] = { 5, 4, 3, 2, 1 };
  cout << (LongestConsecutiveSubsequence(arr_5, 5) == 5 ? 1 : 0) << endl;

  return 0;
}