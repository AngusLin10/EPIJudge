#include "test_framework/generic_test.h"
unsigned long long Add(unsigned long long x, unsigned long long y) {
    unsigned long long sum = 0;
    unsigned long long carry = 0;
    while (x) {
        sum = x ^ y;
        carry = (x & y) << 1;
        y = sum;
        x = carry;
    }
    return y;
}

// O(n^2)
unsigned long long Multiply(unsigned long long x, unsigned long long y) {
    unsigned long long sum = 0;
    while (x) {
        // Examines each bit of x.
        if (x & 1) {
            sum = Add(sum, y);  // O(n)
        }
        x >>= 1, y <<= 1;
    }
    return sum;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "primitive_multiply.cc",
                         "primitive_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}
