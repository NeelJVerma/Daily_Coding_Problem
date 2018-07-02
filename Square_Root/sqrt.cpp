/*Given a real number n, find the square root of n. For example, given n = 9, return 3.*/

#include <iostream>
using namespace std;

int Sqrt(int n) {
  if (n == 0 || n == 1) {
    return n;
  }

  int start = 1;
  int end = n;
  int ret = 0;

  while (start <= end) {
    int mid = start + (end - start) / 2;

    if (mid * mid == n) {
      return mid;
    }

    if (mid * mid < n) {
      start = mid + 1;
      ret = mid;
    } else {
      end = mid - 1;
    }
  }

  return ret;
}

int main() {
  cout << (Sqrt(9) == 3 ? 1 : 0) << endl;
  cout << (Sqrt(4) == 2 ? 1 : 0) << endl;
  cout << (Sqrt(8) == 2 ? 1 : 0) << endl;
  cout << (Sqrt(100) == 10 ? 1 : 0) << endl;
  cout << (Sqrt(237) == 15 ? 1 : 0) << endl;

  return 0;
}