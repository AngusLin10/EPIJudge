#include "test_framework/generic_test.h"
// Method1 O(n)
unsigned long long ClosestIntSameBitCount(unsigned long long x) {
    const int kNumUnsignBits = 64;

    for (int i = 0; i < kNumUnsignBits - 1; ++i) {
        if (((x >> i) & 1) != ((x >> (i + 1)) & 1)) {
            x ^= (1ULL << i) | (1ULL << (i + 1));
            return x;
        }
    }
}

// Method2 O(1)
unsigned long long ClosestIntSameBitCount2(unsigned long long x) {
    unsigned long long lowestBitNotSet = ~x & (x + 1);
    unsigned long long lowestBitSet = x & ~(x - 1);

    if (lowestBitNotSet > lowestBitSet) {
        x |= lowestBitNotSet;
        x ^= lowestBitNotSet >> 1;
    }
    else {
        x ^= lowestBitSet;
        x |= lowestBitSet >> 1;
    }

    return x;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "closest_int_same_weight.cc",
                         "closest_int_same_weight.tsv", &ClosestIntSameBitCount,
                         DefaultComparator{}, param_names);
}
