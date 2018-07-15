/*
Given a pivot x, and a list lst, partition the list into three parts.

The first part contains all elemenets in lst that are less than x
The first part contains all elemenets in lst that are equal to x
The first part contains all elemenets in lst that are larger than x
Ordering within a part can be arbitrary.

For example, given x = 10 and lst = [9, 12, 3, 5, 14, 10, 10], one partition may be `[9, 3, 5, 10, 10, 12, 14]
*/

#include <iostream>
#include <algorithm>
using namespace std;

int* Partition(int* arr, int size, int x) {
  int less = 0;
  int greater = size - 1;
  int* ret_arr = new int[size];

  for (int i = 0; i < size; i++) {
    if (arr[i] < x) {
      ret_arr[less++] = arr[i];
    } else if (arr[i] > x) {
      ret_arr[greater--] = arr[i];
    }
  }

  for (int i = 0; i < size; i++) {
    if (arr[i] == x) {
      ret_arr[less++] = arr[i];
    }
  }

  return ret_arr;
}

void PrintArray(int* arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << ' ';
  }

  cout << endl;
}

int main() {
  int arr_1[] = {9, 12, 3, 5, 14, 10, 10};
  int* ret_arr_1 = Partition(arr_1, 7, 10);
  PrintArray(ret_arr_1, 7);

  int arr_2[] = {3, 3, 3};
  int* ret_arr_2 = Partition(arr_2, 3, 3);
  PrintArray(ret_arr_2, 3);

  int arr_3[] = {1, 2, 3, 4, 5};
  int* ret_arr_3 = Partition(arr_3, 5, 3);
  PrintArray(ret_arr_3, 5);
  
  return 0;
}