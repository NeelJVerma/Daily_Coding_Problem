/*
Given an array of numbers, find the maximum sum of any contiguous subarray of the array.

For example, given the array [34, -50, 42, 14, -5, 86], the maximum sum would be 137, since we would take elements 42, 14, -5, and 86.

Given the array [-5, -1, -8, -9], the maximum sum would be 0, since we would not take any elements.

Do this in O(N) time.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int MaximumSubarraySum(int* arr, int size) {
  int sum = 0;
  int ret_sum = 0;

  for (int i = 0; i < size; i++) {
    sum = max(arr[i], arr[i] + sum);
    ret_sum = max(sum, ret_sum);
  }

  return ret_sum;
}

int main() {
  int arr_1[] = {34, -50, 42, 14, -5, 86};
  cout << (MaximumSubarraySum(arr_1, 6) == 137 ? 1 : 0) << endl;

  int arr_2[] = {-5, -1, -8, -9};
  cout << (MaximumSubarraySum(arr_2, 4) == 0 ? 1 : 0) << endl;
  
  return 0;
}