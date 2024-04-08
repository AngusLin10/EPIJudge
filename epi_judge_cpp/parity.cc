#include "test_framework/generic_test.h"
short Parity(unsigned long long x) {
    int result = 0;
    while (x > 0) {
        result ^= 1; // result = !result  
        x &= (x - 1);
    }
    return result;

    // https://www.geeksforgeeks.org/finding-the-parity-of-a-number-efficiently/
    /*
    x ^= x >> 32;
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    */

    /*
    n = 1000 0101
    n = n ^ (n >> 4) = 1000 ^ 0101 = 1101
    n = n ^ (n >> 2) = 11 ^ 01 = 10
    n = n ^ (n >> 1) = 1 ^ 0 = 1
    Final result = n & 1 = 1
    
    return x & 1;
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
