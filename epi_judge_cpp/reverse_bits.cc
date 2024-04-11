#include "test_framework/generic_test.h"
unsigned long long ReverseBits(unsigned long long x) {                      //    .... 00000000 abcdefgh 
    x = ((x >> 1) & 0x5555555555555555) | ((x & 0x5555555555555555) << 1);  // => .... 00000000 badcfehg
    x = ((x >> 2) & 0x3333333333333333) | ((x & 0x3333333333333333) << 2);  // => .... 00000000 dcbahgfe
    x = ((x >> 4) & 0x0f0f0f0f0f0f0f0f) | ((x & 0x0f0f0f0f0f0f0f0f) << 4);  // => .... 00000000 hgfedcba
    x = ((x >> 8) & 0x00ff00ff00ff00ff) | ((x & 0x00ff00ff00ff00ff) << 8);  // => abcdefgh 00000000 .... 
    x = ((x >> 16) & 0x0000ffff0000ffff) | ((x & 0x0000ffff0000ffff) << 16);
    x = (x >> 32) | (x << 32);
    return x;
}

unsigned long long ReverseBits2(unsigned long long x) {
    unsigned long long r = 0;
    int i = 63;
    while (x >>= 1) {
        r = (r << 1) | (x & 1);
        --i;
    }
    return r << i;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  ReverseBits2(5);
  return GenericTestMain(args, "reverse_bits.cc", "reverse_bits.tsv",
                         &ReverseBits2, DefaultComparator{}, param_names);

}
