#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
// O(n)
vector<int> NextPermutation(vector<int> perm) {
  int n = perm.size();
  int i = n - 2;
  int j = n - 1;
  while (i >= 0 && perm[i] >= perm[i + 1])
    --i;
  if (i >= 0) {
    while (perm[j] <= perm[i])
      --j;
    std::swap(perm[i], perm[j]);
    std::reverse(perm.begin() + i + 1, perm.end());
  } else
    perm = {};

  return perm;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"perm"};
  return GenericTestMain(args, "next_permutation.cc", "next_permutation.tsv",
                         &NextPermutation, DefaultComparator{}, param_names);
}
