/*
Implement integer exponentiation. That is, implement the pow(x, y) function, where x and y are integers and returns x^y.

Do this faster than the naive method of repeated multiplication.

For example, pow(2, 10) should return 1024.
*/

#include <iostream>
using namespace std;

#define ull unsigned long long

ull Pow(ull x, ull y) {
  ull result = 1;

  while (y) {
    if (y & 1) {
      result *= x;
    }

    y >>= 1;
    x *= x;
  }

  return result;
}

int main() {
  cout << (Pow(2, 0) == 1 ? 1 : 0) << endl;
  cout << (Pow(5, 3) == 125 ? 1 : 0) << endl;
  cout << (Pow(3, 3) == 27 ? 1 : 0) << endl;
  cout << (Pow(1, 10) == 1 ? 1 : 0) << endl;
  cout << (Pow(-4, 3) == -64 ? 1 : 0) << endl;

  return 0;
}