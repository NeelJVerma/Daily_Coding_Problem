/*
You are given a 2-d matrix where each cell represents number of coins in that cell. Assuming we start at matrix[0][0], and can only move right or down, find the maximum number of coins you can collect by the bottom right corner.

For example, in this matrix

0 3 1 1
2 0 0 4
1 5 3 1
The most we can collect is 0 + 2 + 1 + 5 + 3 + 1 = 12 coins.
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int kMaxRows = 500;
const int kMaxCols = 500;

int MaxCoins(int coins[kMaxRows][kMaxCols], int rows, int cols) {
  int cost[rows][cols];
  cost[0][0] = coins[0][0];

  for (int i = 1; i < rows; i++) {
    cost[i][0] = coins[i][0] + cost[i - 1][0];
  }

  for (int j = 1; j < cols; j++) {
    cost[0][j] = coins[0][j] + cost[0][j - 1];
  }

  for (int i = 1; i < rows; i++) {
    for (int j = 1; j < cols; j++) {
      cost[i][j] = max(cost[i - 1][j], cost[i][j - 1]) + coins[i][j];
    }
  }

  return cost[rows - 1][cols - 1];
}

int main() {
  int coins_1[kMaxRows][kMaxCols] = {
    { 0, 3, 1, 1 },
    { 2, 0, 0, 4 },
    { 1, 5, 3, 1 }
  };
  cout << (MaxCoins(coins_1, 3, 4) == 12 ? 1 : 0) << endl;

  int coins_2[kMaxRows][kMaxCols] = {
    { 1, 2, 3, 4 }
  };
  cout << (MaxCoins(coins_2, 1, 4) == 10 ? 1 : 0) << endl;

  int coins_3[kMaxRows][kMaxCols] = {
    { 1, 2, 3, 4 },
    { 5, 6, 7, 8 }
  };
  cout << (MaxCoins(coins_3, 2, 4) == 27 ? 1 : 0) << endl;

  return 0;
}