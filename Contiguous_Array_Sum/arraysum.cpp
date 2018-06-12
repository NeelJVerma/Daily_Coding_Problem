/*
Given a list of integers and a number K, return which contiguous elements of the list sum to K.

For example, if the list is [1, 2, 3, 4, 5] and K is 9, then it should return [2, 3, 4].

Assume a solution always exists.
*/

#include <iostream>
#include <vector>
using namespace std;

#define pb push_back

vector<int> ContiguousArraySum(int* arr, int size, int k) {
  if (size == 1) {
    vector<int> return_sub(1, arr[0]);

    return return_sub;
  }

  int start_idx = 0;
  int end_idx = 0;
  int dp[size][size] = { 0 };

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (j < i) {
        continue;
      }

      if (j == i) {
        dp[i][j] = arr[i];

        continue;
      }

      dp[i][j] = arr[j] + dp[i][j - 1];

      if (dp[i][j] == k) {
        start_idx = i;
        end_idx = j;

        vector<int> return_sub;

        for (int i = start_idx; i <= end_idx; i++) {
          return_sub.pb(arr[i]);
        }

        return return_sub;
      }
    }
  }
}

int main() {
  int arr_1[] = { 1, 2, 3, 4, 5 };
  vector<int> return_sub_1 = ContiguousArraySum(arr_1, 5, 9);
  for (int i : return_sub_1) {
    cout << i << ' ';
  }
  cout << endl;

  int arr_2[] = { 7, 4, 8, 1, -2 };
  vector<int> return_sub_2 = ContiguousArraySum(arr_2, 5, 12);
  for (int i : return_sub_2) {
    cout << i << ' ';
  }
  cout << endl;

  int arr_3[] = { 1 };
  vector<int> return_sub_3 = ContiguousArraySum(arr_3, 1, 1);
  for (int i : return_sub_3) {
    cout << i << ' ';
  }
  cout << endl;

  return 0;
}