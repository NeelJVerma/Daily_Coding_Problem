/*
Given a list of numbers L, implement a method sum(i, j) which returns the sum from the sublist L[i:j] (including i, excluding j).

For example, given L = [1, 2, 3, 4, 5], sum(1, 3) should return sum([2, 3]), which is 5.
*/

#include <iostream>
using namespace std;

int Sum(int* arr, int i, int j) {
  if (i == j) {
    return arr[i];
  }

  int sum = 0;

  while (i < j) {
    sum += arr[i++];
  }

  return sum;
}

int main() {
  int arr_1[] = {1, 2, 3, 4, 5};
  cout << (Sum(arr_1, 1, 3) == 5 ? 1 : 0) << endl;
  cout << (Sum(arr_1, 0, 4) == 10 ? 1 : 0) << endl;
  cout << (Sum(arr_1, 1, 1) == 2 ? 1 : 0) << endl;
  
  return 0;
}