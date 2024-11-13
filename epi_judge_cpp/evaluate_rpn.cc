#include <string>

#include "test_framework/generic_test.h"
using std::string;

// O(n)
int Evaluate(const string& expression) {
    std::stack<int> stack;
    string number;
    for (auto& c : expression) {
        if (std::isdigit(c)) {
            number += c;
        }
        else if (c == ',' && !number.empty()) {
            stack.emplace(std::stoi(number));
            number = "";
        }
        else if (c != ',' && stack.size() > 1) {
            int y = stack.top();
            stack.pop();
            int x = stack.top();
            stack.pop();
            switch (c) {
                case '+':
                    stack.emplace(x + y);
                    break;
                case '-':
                    stack.emplace(x - y);
                    break;
                case '*':
                    stack.emplace(x * y);
                    break;
                case '/':
                    stack.emplace(x / y);
                    break;
            }
        }
    }

    if (!number.empty()) {
        stack.emplace(std::stoi(number));
    }

    return stack.top();
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"expression"};
  return GenericTestMain(args, "evaluate_rpn.cc", "evaluate_rpn.tsv", &Evaluate,
                         DefaultComparator{}, param_names);
}
