#include "test_framework/generic_test.h"

// reference: https://www.geeksforgeeks.org/finding-the-parity-of-a-number-efficiently/

// Method 1 O(k) For example, for 10001010, k = 3.
short Parity(unsigned long long x) {
    short result = 0;
    while (x > 0) {
        result ^= 1;  // Since result is initially 0 or 1, result ^= 1; is equivalent to result = !result;
        x &= (x - 1); // Drops the lowest set bit of x. example: x = 1000 0101, x & (x - 1) = 1000 0100
    }
    return result;
}

// Method 2 O(log(n)), where n is the word size.
short Parity2(unsigned long long x) {
    x ^= x >> 32;
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;

    return x & 1;

    /*
    example:
        x = 1000 0101
        x = x ^ (x >> 4) = 1000 ^ 0101 = 1101
        x = x ^ (x >> 2) = 11 ^ 01 = 10
        x = x ^ (x >> 1) = 1 ^ 0 = 1
        Final result = x & 1 = 1
    */
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "parity.cc", "parity.tsv", &Parity,
                         DefaultComparator{}, param_names);
  /*
  int n = Parity(16);
  std::cout << "n =" << n;
  return 0;
  */
}
