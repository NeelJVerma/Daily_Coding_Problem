/*
Given a 32-bit integer, return the number with its bits reversed.

For example, given the binary number 1111 0000 1111 0000 1111 0000 1111 0000, return 0000 1111 0000 1111 0000 1111 0000 1111.
*/

#include <iostream>

const int kNumBits = 32;

unsigned ReverseBits(const unsigned& num) {
  unsigned rev = 0;

  for (int i = 0; i < kNumBits; i++) {
    if (num & (1 << i)) {
      rev |= (1 << ((kNumBits - 1) - i));
    }
  }

  return rev;
}

int main() {
  std::cout << (ReverseBits(1) == 2147483648 ? 1 : 0) << std::endl;
  std::cout << (ReverseBits(2147483648) == 1 ? 1 : 0) << std::endl;

  return 0;
}