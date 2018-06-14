/*
We can determine how "out of order" an array A is by counting the number of inversions it has. Two elements A[i] and A[j] form an inversion if A[i] > A[j] but i < j. That is, a smaller element appears after a larger element.

Given an array, count the number of inversions it has. Do this faster than O(N^2) time.

You may assume each element in the array is distinct.

For example, a sorted list has zero inversions. The array [2, 4, 1, 3, 5] has three inversions: (2, 1), (4, 1), and (4, 3). The array [5, 4, 3, 2, 1] has ten inversions: every distinct pair forms an inversion.
*/

#include <iostream>
using namespace std;

int Merge(int* arr, int left, int middle, int right) {
  int size_1 = middle - left + 1;
  int size_2 = right - middle;
  int left_arr[size_1];
  int right_arr[size_2];
  int total_inversions = 0;

  for (int i = 0; i < size_1; i++) {
    left_arr[i] = arr[left + i];
  }

  for (int i = 0; i < size_2; i++) {
    right_arr[i] = arr[middle + i + 1];
  }

  int i = 0;
  int j = 0;
  int k = left;
  int l = left;

  while (i < size_1 && j < size_2) {
    if (left_arr[i] <= right_arr[j]) {
      arr[k] = left_arr[i];
      i++;
      l++;
    } else {
      total_inversions += (middle - l + 1);
      arr[k] = right_arr[j];
      j++;
    }

    k++;
  }

  while (i < size_1) {
    arr[k] = left_arr[i];
    i++;
    k++;
  }

  while (j < size_2) {
    arr[k] = right_arr[j];
    j++;
    k++;
  }

  return total_inversions;
}

int InversionsUtil(int* arr, int left, int right) {
  if (left == right) {
    return 0;
  }

  int middle = (left + right) / 2;
  int left_inversions = InversionsUtil(arr, left, middle);
  int right_inversions = InversionsUtil(arr, middle + 1, right);
  int merge_inversions = Merge(arr, left, middle, right);

  return left_inversions + right_inversions + merge_inversions;
}

int Inversions(int* arr, int size) {
  return InversionsUtil(arr, 0, size - 1);
}

int main() {
  int arr_1[] = { 1, 2, 3, 4, 5 };
  cout << (Inversions(arr_1, 5) == 0 ? 1 : 0) << endl;

  int arr_2[] = { 5, 4, 3, 2, 1 };
  cout << (Inversions(arr_2, 5) == 10 ? 1 : 0) << endl;

  int arr_3[] = { 2, 4, 1, 3, 5 };
  cout << (Inversions(arr_3, 5) == 3 ? 1 : 0) << endl;

  return 0;
}