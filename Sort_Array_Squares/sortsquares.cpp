/*
Given a sorted list of integers, square the elements and give the output in sorted order.

For example, given [-9, -2, 0, 2, 3], return [0, 4, 4, 9, 81].
*/

#include <iostream>
using namespace std;

int* SortSquares(int* arr, int size) {
  int* ret = new int[size];
  int pos_idx;
  int neg_idx;
  int ret_idx = 0;

  for (int i = 0; i < size; i++) {
    if (arr[i] >= 0) {
      pos_idx = i;
      break;
    }
  }

  neg_idx = pos_idx - 1;

  while (pos_idx < size && neg_idx >= 0) {
    int pos_squared = arr[pos_idx] * arr[pos_idx];
    int neg_squared = arr[neg_idx] * arr[neg_idx];

    if (pos_squared < neg_squared) {
      ret[ret_idx] = pos_squared;
      pos_idx++;
    } else {
      ret[ret_idx] = neg_squared;
      neg_idx--;
    }

    ret_idx++;
  }

  while (pos_idx < size) {
    int pos_squared = arr[pos_idx] * arr[pos_idx];
    ret[ret_idx] = pos_squared;
    pos_idx++;
    ret_idx++;
  }

  while (neg_idx >= 0) {
    int neg_squared = arr[neg_idx] * arr[neg_idx];
    ret[ret_idx] = neg_squared;
    neg_idx--;
    ret_idx++;
  }

  return ret;
}

void PrintArray(int* arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << ' ';
  }

  cout << endl;
}

int main() {
  int arr_1[] = { -9, -2, 0, 2, 3 };
  int* ret_arr_1 = SortSquares(arr_1, 5);
  PrintArray(ret_arr_1, 5);

  int arr_2[] = { 1, 1, 1, 1, 1 };
  int* ret_arr_2 = SortSquares(arr_2, 5);
  PrintArray(ret_arr_2, 5);

  int arr_3[] = { 0, 1, 1, 1, 1 };
  int* ret_arr_3 = SortSquares(arr_3, 5);
  PrintArray(ret_arr_3, 5);

  int arr_4[] = { 1, 2, 3 };
  int* ret_arr_4 = SortSquares(arr_4, 3);
  PrintArray(ret_arr_4, 3);

  int arr_5[] = { -10, -5, 1, 10 };
  int* ret_arr_5 = SortSquares(arr_5, 4);
  PrintArray(ret_arr_5, 4);

  return 0;
}