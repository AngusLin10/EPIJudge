#include <string>
#include <vector>

#include "test_framework/generic_test.h"
using std::string;
using std::vector;

// O(4^n)
vector<string> PhoneMnemonic(const string& phone_number) {
    if (phone_number.empty()) 
        return {};
    vector<string> dict{ "0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };
    vector<string> result{""};
    vector<string> currentCombinations;
    for (const auto& num : phone_number) {
        currentCombinations.clear();
        string str = dict[num - '0'];
        for (const auto& ch : str) {
            for (const auto& combination : result) {
                currentCombinations.emplace_back(combination + ch);
            }
        }
        result = std::move(currentCombinations);
    }

    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"phone_number"};
  const string number = "99";
  vector<string> result = PhoneMnemonic(number);
  return GenericTestMain(args, "phone_number_mnemonic.cc",
                         "phone_number_mnemonic.tsv", &PhoneMnemonic,
                         UnorderedComparator{}, param_names);
}
