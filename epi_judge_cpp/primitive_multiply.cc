#include "test_framework/generic_test.h"
// O(n)
unsigned long long Add(unsigned long long x, unsigned long long y) {
    while (x) {
        unsigned long long carry = x & y;
        y = x ^ y;
        x = carry << 1;
    }
    return y;
}

unsigned long long Multiply(unsigned long long x, unsigned long long y) {
    unsigned long long sum = 0;
    while (x) {
        // Examines each bit of x.
        if (x & 1) {
            sum = Add(sum, y);
        }
        x >>= 1, y <<= 1;
    }
    return sum;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  Multiply(13, 9);
  return GenericTestMain(args, "primitive_multiply.cc",
                         "primitive_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}
