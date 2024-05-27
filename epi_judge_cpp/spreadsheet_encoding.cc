#include <string>

#include "test_framework/generic_test.h"
using std::string;

int SSDecodeColID(const string& col) {
  int result = 0;
  for (char c: col) {
    result = result * 26 + (c - 'A' + 1);
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"col"};
  return GenericTestMain(args, "spreadsheet_encoding.cc",
                         "spreadsheet_encoding.tsv", &SSDecodeColID,
                         DefaultComparator{}, param_names);
}
