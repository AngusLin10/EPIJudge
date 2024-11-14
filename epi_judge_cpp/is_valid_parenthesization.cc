#include <string>

#include "test_framework/generic_test.h"
using std::string;
bool IsWellFormed(const string& s) {
    std::stack<char> rightChars;
    for (auto& c : s) {
        if (c == '(') rightChars.emplace(')');
        else if (c == '{') rightChars.emplace('}');
        else if (c == '[') rightChars.emplace(']');
        else {
            if (rightChars.empty() || rightChars.top() != c)
                return false;
            rightChars.pop();
        }
    }

    return rightChars.empty();
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "is_valid_parenthesization.cc",
                         "is_valid_parenthesization.tsv", &IsWellFormed,
                         DefaultComparator{}, param_names);
}
