/*
Given an array of numbers, find the length of the longest increasing subsequence in the array. The subsequence does not necessarily have to be contiguous.

For example, given the array [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15], the longest increasing subsequence has length 6: it is 0, 2, 6, 9, 11, 15.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int MaxOfArray(int* arr, int size) {
  int max = 0;

  for (int i = 0; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  return max;
}

int LongestIncreasingSubsequence(int* arr, int size) {
  int dp[size] = { 1 };

  for (int i = 1; i < size; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[i] > arr[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  return MaxOfArray(dp, size);
}

int main() {
  int arr_1[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
  cout << (LongestIncreasingSubsequence(arr_1, 16) == 6 ? 1 : 0) << endl;

  int arr_2[] = {1, 7, 2, 9, 8, 6, 4, 10 };
  cout << (LongestIncreasingSubsequence(arr_2, 8) == 4 ? 1 : 0) << endl;

  int arr_3[] = { 1, 2, 3, 4, 5 };
  cout << (LongestIncreasingSubsequence(arr_3, 5) == 5 ? 1 : 0) << endl;

  int arr_4[] = { 5, 4, 3, 2, 1 };
  cout << (LongestIncreasingSubsequence(arr_4, 5) == 1 ? 1 : 0) << endl;

  return 0;
}