/*
Write a function that rotates a list by k elements. For example, [1, 2, 3, 4, 5, 6] rotated by two becomes [3, 4, 5, 6, 1, 2].
Try solving this without creating a copy of the list. How many swap or move operations do you need?
*/

#include <iostream>
#include <unordered_map>
using namespace std;

void Rotate(int* arr, int size, int k) {
  int actual_k = k % size;
  unordered_map<int, int> index_to_data;

  for (int i = 0; i < size; i++) {
    index_to_data[i] = arr[i];
  }

  for (int i = 0; i < size; i++) {
    if (i >= actual_k) {
      arr[i - actual_k] = index_to_data[i];
    } else {
      arr[size + i - actual_k] = index_to_data[i];
    }
  }
}

void PrintArray(int* arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << ' ';
  }

  cout << endl;
}

int main() {
  int arr_1[] = {1, 2, 3, 4, 5, 6};
  Rotate(arr_1, 6, 2);
  PrintArray(arr_1, 6);

  int arr_2[] = {1, 2, 3, 4, 5, 6};
  Rotate(arr_2, 6, 0);
  PrintArray(arr_2, 6);

  int arr_3[] = {1, 2, 3, 4};
  Rotate(arr_3, 4, 5);
  PrintArray(arr_3, 4);

  int arr_4[] = {1};
  Rotate(arr_4, 1, 100);
  PrintArray(arr_4, 1);

  int arr_5[] = {1, 2};
  Rotate(arr_5, 2, 10);
  PrintArray(arr_5, 2);

  return 0;
}