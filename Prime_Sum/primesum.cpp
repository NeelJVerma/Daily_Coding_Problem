/*
Given an even number (greater than 2), return two prime numbers whose sum will be equal to the given number.

A solution will always exist. See Goldbach’s conjecture.

Example:

Input: 4
Output: 2 + 2 = 4
If there are more than one solution possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b, and [c, d] is another solution with c <= d, then

[a, b] < [c, d]
If a < c OR a==c AND b < d.
*/

#include <iostream>
#include <utility>
using namespace std;

void FillPrimes(int n, bool* primes) {
  for (int i = 0; i <= n; i++) {
    primes[i] = true;
  }

  primes[0] = primes[1] = false;

  for (int i = 2; i <= n; i++) {
    if (primes[i]) {
      for (int j = (i * i); j <= n; j += i) {
        primes[j] = false;
      }
    }
  }
}

pair<int, int> PrimeSum(int n) {
  bool primes[n + 1];
  FillPrimes(n, primes);

  for (int i = 2; i <= n; i++) {
    if (primes[i] && primes[n - i]) {
      pair<int, int> sum = make_pair(i, n - i);

      return sum;
    }
  }
}

int main() {
  pair<int, int> sum_1 = PrimeSum(4);
  cout << sum_1.first << ' ' << sum_1.second << endl;

  pair<int, int> sum_2 = PrimeSum(18);
  cout << sum_2.first << ' ' << sum_2.second << endl;

  pair<int, int> sum_3 = PrimeSum(100);
  cout << sum_3.first << ' ' << sum_3.second << endl;

  pair<int, int> sum_4 = PrimeSum(24);
  cout << sum_4.first << ' ' << sum_4.second << endl;

  pair<int, int> sum_5 = PrimeSum(25002);
  cout << sum_5.first << ' ' << sum_5.second << endl;

  return 0;
}