#include <string>

#include "test_framework/generic_test.h"
using std::string;

string LookAndSay(int n) {
  string result = "1";
  while (--n) {
    string next;
    for (int i = 0; i < result.size(); ++i) {
      int count = 1;
      while (result[i] == result[i + 1] && i < result.size() - 1) {
        ++count, ++i;
      }
      next += std::to_string(count) + result[i];
    }
    result = std::move(next);
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  LookAndSay(10);
  return GenericTestMain(args, "look_and_say.cc", "look_and_say.tsv",
                         &LookAndSay, DefaultComparator{}, param_names);
}
