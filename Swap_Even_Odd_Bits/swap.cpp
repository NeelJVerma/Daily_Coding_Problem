#include <iostream>
using namespace std;

const int kMaxBits = 8;

uint8_t SwapBits(uint8_t n) {
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
  cout << unsigned(SwapBits(254)) << endl;
  
  return 0;
}