/*
Given an array of numbers and a number k, determine if there are three entries in the array which add up to the specified number k. For example, given [20, 303, 3, 4, 25] and k = 49, return true as 20 + 4 + 25 = 49.
*/

#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

bool SumExists(int* arr, int size, int k) {
  if (size < 3) {
    return false;
  }

  sort(arr, arr + size);
  int current_sum = arr[0];
  int window_size = 1;
  int start = arr[0];

  for (int i = 1; i < size; i++) {
    current_sum += arr[i];
    window_size++;

    if (current_sum > k || window_size > 3) {
      current_sum -= start;
      start = arr[i - window_size + 1];
      window_size--;
    }

    if (current_sum == k) {
      return true;
    }
  }

  return false;
}

int main() {
  int arr1[] = {20, 303, 3, 4, 25};
  int arr2[] = {1, 2};
  int arr3[] = {1, 2, 3};
  int arr4[] = {1, 7, 6, 1, 1};

  assert(SumExists(arr1, 5, 49) == true);
  assert(SumExists(arr1, 5, 50) == false);
  assert(SumExists(arr1, 5, 23) == false);
  assert(SumExists(arr1, 5, 27) == true);
  assert(SumExists(arr1, 2, 2) == false);
  assert(SumExists(arr3, 3, 6) == true);
  assert(SumExists(arr3, 3, 1) == false);
  assert(SumExists(arr4, 5, 3) == true);

  return 0;
}