#include <iostream>
#include <unordered_set>
using namespace std;

// Time complexity: O(n)

bool TwoSum(int arr[], int n, int sum) {
  unordered_set<int> complements;

  for (int i = 0; i < n; i++) {
    if (complements.find(arr[i]) != complements.end()) {
      return true;
    }

    complements.insert(sum - arr[i]);
  }

  return false;
}

int main() {
  int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  int n = sizeof(arr) / sizeof(int);

  cout << TwoSum(arr, n, 3) << endl;
  return 0;
}
