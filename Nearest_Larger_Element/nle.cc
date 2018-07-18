/*
Given an array of numbers and an index i, return the index of the nearest larger number of the number at index i, where distance is measured in array indices.

For example, given [4, 1, 3, 5, 6] and index 0, you should return 3.

If two distances to larger numbers are the equal, then return any one of them. If the array at i doesn't have a nearest larger integer, then return null.

Follow-up: If you can preprocess the array, can you do this in constant time?
*/

#include <iostream>
#include <stack>
#include <limits>
#include <algorithm>
using namespace std;

const int kInfinity = numeric_limits<long double>::infinity();

int NearestLargerNumber(int* arr, int size, int index) {
  /*******************
  **** PREPROCESS ****
  ********************/

  stack<int> indices;
  indices.push(0);
  int* pre = new int[size];

  for (int i = 1; i < size; i++) {
    if (indices.empty()) {
      indices.push(i);
      continue;
    }

    while (!indices.empty() && arr[indices.top()] < arr[i]) {
      pre[indices.top()] = i;
      indices.pop();
    }

    indices.push(i);
  }

  while (!indices.empty()) {
    pre[indices.top()] = kInfinity;
    indices.pop();
  }

  indices.push(size - 1);

  for (int i = size - 2; i >= 0; i--) {
    if (indices.empty()) {
      indices.push(i);
      continue;
    }

    while (!indices.empty() && arr[indices.top()] < arr[i]) {
      if (abs(indices.top() - i) > abs(pre[indices.top()] - i)) {
        pre[indices.top()] = i;
      }

      indices.pop();
    }

    indices.push(i);
  }

  while (!indices.empty()) {
    indices.pop();
  }

  /**********************
  **** CONSTANT TIME ****
  ***********************/

  if (pre[index] == kInfinity) {
    return 0;
  }

  return pre[index];
}

int main() {
  int arr_1[] = {4, 1, 3, 5, 6};
  cout << (NearestLargerNumber(arr_1, 5, 5) == 0 ? 1 : 0) << endl;
  cout << (NearestLargerNumber(arr_1, 5, 2) == 3 ? 1 : 0) << endl;
  cout << (NearestLargerNumber(arr_1, 5, 0) == 3 ? 1 : 0) << endl;

  return 0;
}