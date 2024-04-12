#include "test_framework/generic_test.h"
unsigned long long ReverseBits(unsigned long long x) {
    unsigned long long rev = 0;
    // Iterate through bits from the lowest to the highest
    for (int i = 0; i < sizeof(x) * 8; ++i) {
        // Left shift the reversed result by 1 to prepare for the next bit reversal
        rev <<= 1;

        // If the lowest bit of the input number x is 1, set the lowest bit of the reversed result to 1
        if (x & 1)
            rev |= 1;

        // Right shift the input number x to prepare the next bit as the lowest bit
        x >>= 1;
    }
    return rev;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  ReverseBits(3);
  return GenericTestMain(args, "reverse_bits.cc", "reverse_bits.tsv",
                         &ReverseBits, DefaultComparator{}, param_names);

}
