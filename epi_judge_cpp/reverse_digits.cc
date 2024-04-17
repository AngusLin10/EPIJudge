#include "test_framework/generic_test.h"
// O(n), where n is the number of digits in k. 
long long Reverse(int x) {
    long long result = 0;
    while (x) {
        result = result * 10 + x % 10;
        x /= 10;
    }
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "reverse_digits.cc", "reverse_digits.tsv",
                         &Reverse, DefaultComparator{}, param_names);
}
