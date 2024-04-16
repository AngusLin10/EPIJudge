#include "test_framework/generic_test.h"
int Divide(int x, int y) {
  int quotient = 0;
  int powerOfTwo = 32;
  unsigned int shiftedDivisor = static_cast<unsigned int>(y) << powerOfTwo;
  while (x >= y) {
    while (shiftedDivisor > x) {
      shiftedDivisor >>= 1;
      --powerOfTwo;
    }
    x -= shiftedDivisor;
    quotient += 1 << powerOfTwo;
  }
  return quotient;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "primitive_divide.cc", "primitive_divide.tsv",
                         &Divide, DefaultComparator{}, param_names);
}
