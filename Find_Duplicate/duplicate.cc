/*
You are given an array of length n + 1 whose elements belong to the set {1, 2, ..., n}.
By the pigeonhole principle, there must be a duplicate. Find it in linear time and space.
*/

#include <iostream>

int FindDuplicate(int* arr, int size) {
  for (int i = 0; i < size; i++) {
    if (arr[abs(arr[i])] < 0) {
      return abs(arr[i]);
    } else {
      arr[abs(arr[i])] = -arr[abs(arr[i])];
    }
  }
}

int main() {
  int arr_1[] = {1, 2, 5, 4, 3, 4};
  std::cout << (FindDuplicate(arr_1, 6) == 4 ? 1 : 0) << std::endl;

  int arr_2[] = {1, 1};
  std::cout << (FindDuplicate(arr_2, 2) == 1 ? 1 : 0) << std::endl;

  int arr_3[] = {4, 3, 2, 1, 4};
  std::cout << (FindDuplicate(arr_3, 5) == 4 ? 1 : 0) << std::endl;

  return 0;
}