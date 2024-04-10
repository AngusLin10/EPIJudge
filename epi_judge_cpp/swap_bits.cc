#include "test_framework/generic_test.h"
long long SwapBits(long long x, int i, int j) {
    if (((x >> i) & 1) != ((x >> j) & 1)) { // i-th and j-th bits differ. 
        long long mask = (1LL <<  i) | (1LL << j); // example: (i=0, j=3) => mask = 1001
        x ^= mask;  // Since x^1 = 0 when x = 1 and x^1 = 1 when x = 0
    }
    return x;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "i", "j"};
  return GenericTestMain(args, "swap_bits.cc", "swap_bits.tsv", &SwapBits,
                         DefaultComparator{}, param_names);
}
