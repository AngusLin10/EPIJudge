#include <algorithm>
#include <string>
#include <vector>

#include "test_framework/generic_test.h"
using std::string;
using std::vector;

bool isValid(const string s) {
  return !(s.size() > 3 || (s.size() > 1 && s[0] == '0') || stoi(s) > 255);
}

vector<string> GetValidIpAddress(const string& s) {
  vector<string> result;
  for (int i = 1; i < 4 && i < s.size(); ++i) {
    for (int j = i + 1; j < i + 4 && j < s.size(); ++j) {
      for (int k = j + 1; k < j + 4 && k < s.size(); ++k) {
        string first = s.substr(0, i);
        string second = s.substr(i, j - i);
        string third = s.substr(j, k - j);
        string fourth = s.substr(k, s.size() - k);
        if (isValid(first) && isValid(second) && isValid(third) && isValid(fourth))
          result.emplace_back(first + '.' + second + '.' + third + '.' + fourth);
      }
    }
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "valid_ip_addresses.cc",
                         "valid_ip_addresses.tsv", &GetValidIpAddress,
                         UnorderedComparator{}, param_names);
}
