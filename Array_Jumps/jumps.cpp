/*
Given an integer list where each number represents the number of hops you can make, determine whether you can reach to the last index starting at index 0.

For example, [2, 0, 1, 0] returns true while [1, 1, 0, 1] returns false.
*/

#include <iostream>
using namespace std;

bool CanJumpToEnd(int arr[], int size) {
  int i = 0;

  while (i < size) {
    if (arr[i] == 0 && i != size - 1) {
      return false;
    }

    if (i == size - 1) {
      return true;
    }

    i += arr[i];
  }

  return !(i >= size);
}

int main() {
  int arr_1[] = { 2, 0, 1, 0 };
  cout << (CanJumpToEnd(arr_1, 4) ? 1 : 0) << endl;

  int arr_2[] = { 1, 1, 0, 1 };
  cout << (!CanJumpToEnd(arr_2, 4) ? 1 : 0) << endl;

  int arr_3[] = { 1 };
  cout << (CanJumpToEnd(arr_3, 1) ? 1 : 0) << endl;

  int arr_4[] = { 0 };
  cout << (CanJumpToEnd(arr_4, 1) ? 1 : 0) << endl;

  int arr_5[] = { 1, 1, 1 };
  cout << (CanJumpToEnd(arr_5, 3) ? 1 : 0) << endl;

  int arr_6[] = { 2, 1 };
  cout << (!CanJumpToEnd(arr_6, 2) ? 1 : 0) << endl;

  return 0;
}