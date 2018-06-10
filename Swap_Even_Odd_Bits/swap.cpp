/*
Given an unsigned 8-bit integer, swap its even and odd bits. The 1st and 2nd bit should be swapped, the 3rd and 4th bit should be swapped, and so on.

For example, 10101010 should be 01010101.
*/

#include <iostream>
using namespace std;

const int kMaxBits = 8;

uint8_t SwapBits(uint8_t n) {
  if (!n) {
    return 1;
  }

  for (int i = kMaxBits - 1; i >= 0; i -= 2) {
    uint8_t first_bit = (n >> i) & 1;
    uint8_t second_bit = (n >> (i - 1)) & 1;
    
    if (first_bit + second_bit == 1) {
      uint8_t mask = (3 << (i - 1));
      n ^= mask;
    }
  }

  return n;
}

int main() {
  cout << unsigned(SwapBits(2)) << endl;

  return 0;
}