/*
An sorted array of integers was rotated an unknown number of times.

Given such an array, find the index of the element in the array in faster than linear time. If the element doesn't exist in the array, return null.

For example, given the array [13, 18, 25, 2, 8, 10] and the element 8, return 4 (the index of 8 in the array).

You can assume all the integers in the array are unique.
*/

#include <iostream>
using namespace std;

int FindUtil(int* arr, int size, int left, int right, int num) {
  int mid = (left + right) / 2;

  if (arr[mid] == num) {
    return mid;
  }

  if ((num >= arr[left] && num <= arr[mid - 1]) ||
      (num <= arr[left] && num >= arr[mid - 1])) {
    return FindUtil(arr, size, left, mid - 1, num);
  }

  if ((num >= arr[right] && num <= arr[mid + 1]) ||
      (num <= arr[right] && num >= arr[mid + 1])) {
    return FindUtil(arr, size, mid + 1, right, num);
  }
}

int Find(int* arr, int size, int num) {
  return FindUtil(arr, size, 0, size - 1, num);
}

int main() {
  int arr_1[] = { 13, 18, 25, 2, 8, 10 };
  cout << (Find(arr_1, 6, 8) == 4 ? 1 : 0) << endl;

  int arr_2[] = { 12, 13, 14, 15, 16, 17 };
  cout << (Find(arr_2, 6, 12) == 0 ? 1 : 0) << endl;

  int arr_3[] = { 1 };
  cout << (Find(arr_3, 1, 1) == 0 ? 1 : 0) << endl;

  int arr_4[] = { 14, 13, 12, 15 };
  cout << (Find(arr_4, 4, 15) == 3 ? 1 : 0) << endl;

  int arr_5[] = { 1, 2, 3, -3, -2, -1 };
  cout << (Find(arr_5, 6, -2) == 4 ? 1 : 0) << endl;

  return 0;
}