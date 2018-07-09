/*
Find the minimum number of coins required to make n cents.

You can use standard American denominations, that is, 1¢, 5¢, 10¢, and 25¢.

For example, given n = 16, return 3 since we can make it with a 10¢, a 5¢, and a 1¢.
*/

#include <iostream>
using namespace std;

const int kCoins[] = {1, 5, 10, 25};

int FindClosestCoin(int num_coins) {
  if (kCoins[3] <= num_coins) {
    return kCoins[3];
  }

  if (kCoins[2] <= num_coins) {
    return kCoins[2];
  }

  if (kCoins[1] <= num_coins) {
    return kCoins[1];
  }

  return kCoins[0];
}

int MinimumCoins(int num_coins) {
  int min_coins = 0;

  while (num_coins) {
    int closest_coin = FindClosestCoin(num_coins);
    min_coins += (num_coins / closest_coin);
    num_coins %= closest_coin;
  }

  return min_coins;
}

int main() {
  cout << (MinimumCoins(11) == 2 ? 1 : 0) << endl;
  cout << (MinimumCoins(45) == 3 ? 1 : 0) << endl;
  cout << (MinimumCoins(0) == 0 ? 1 : 0) << endl;
  cout << (MinimumCoins(1) == 1 ? 1 : 0) << endl;
  cout << (MinimumCoins(4) == 4 ? 1 : 0) << endl;

  return 0;
}