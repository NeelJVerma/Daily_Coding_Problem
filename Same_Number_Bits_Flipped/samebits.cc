/*
Given an integer n, find the next biggest integer with the same number of 1-bits on. For example, given the number 6 (0110 in binary), return 9 (1001).
*/

#include <iostream>
#include <cassert>
using namespace std;

const int kNumBits = 32;

int CountSetBits(const int &num) {
  int count = 0;

  for (int i = 0; i < kNumBits; i++) {
    count += ((num >> i) & 1);
  }

  return count;
}

int FindNextSameBitInt(const int &num) {
  if (!num) {
    return 0;
  }

  int local_num = num + 1;
  int num_bits_to_check = CountSetBits(num);

  while (CountSetBits(local_num) != num_bits_to_check) {
    local_num++;
  }

  return local_num;
}

int main() {
  assert(FindNextSameBitInt(6) == 9);
  assert(FindNextSameBitInt(2) == 4);
  assert(FindNextSameBitInt(0) == 0);
  assert(FindNextSameBitInt(7) == 11);
  
  return 0;
}