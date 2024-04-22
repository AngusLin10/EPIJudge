#include "test_framework/generic_test.h"
// O(n)
bool IsPalindromeNumber(int x) {
  // x < 0 or last digit of the number is 0, x is not a palindrome.
  if (x < 0 || (x > 0 && x % 10 == 0))
    return false;

  // Reverse half of the number
  int reversed = 0;
  while (x > reversed) {
    reversed = reversed * 10 + x % 10;
    x /= 10;
  }
  // odd number of digits, remove the middle digit
  return x == reversed || x == reversed / 10;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "is_number_palindromic.cc",
                         "is_number_palindromic.tsv", &IsPalindromeNumber,
                         DefaultComparator{}, param_names);
}
