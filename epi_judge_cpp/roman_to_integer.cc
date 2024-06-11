#include <string>

#include "test_framework/generic_test.h"
using std::string;
// O(n)
int RomanToInteger(const string& s) {
  std::map<char, int> mapping = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
  };
  int sum = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (mapping[s[i]] < mapping[s[i + 1]])
      sum -= mapping[s[i]];
    else
      sum += mapping[s[i]];
  }
  return sum;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "roman_to_integer.cc", "roman_to_integer.tsv",
                         &RomanToInteger, DefaultComparator{}, param_names);
}
