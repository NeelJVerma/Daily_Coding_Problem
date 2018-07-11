/*
Given an array of integers in which two elements appear exactly once and all other elements appear exactly twice, find the two elements that appear only once.

For example, given the array [2, 4, 6, 8, 10, 2, 6, 10], return 4 and 8. The order does not matter.

Follow-up: Can you do this in linear time and constant space?
*/

#include <iostream>
using namespace std;

struct IntPair {
  int x;
  int y;

  IntPair() {
    x = 0;
    y = 0;
  }
};

IntPair GetTwoUniqueElements(int* arr, int size) {
  IntPair pair;
  int xor_of_all = arr[0];

  for (int i = 1; i < size; i++) {
    xor_of_all ^= arr[i];
  }

  int first_set_bit = xor_of_all & ~(xor_of_all - 1);

  for (int i = 0; i < size; i++) {
    if (arr[i] & first_set_bit) {
      pair.x ^= arr[i];
    } else {
      pair.y ^= arr[i];
    }
  }

  return pair;
}

int main() {
  int arr[] = {2, 4, 6, 8, 10, 2, 6, 10};
  IntPair pair = GetTwoUniqueElements(arr, 8);
  cout << pair.x << ' ' << pair.y << endl;
  return 0;
}