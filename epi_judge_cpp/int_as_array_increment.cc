#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
// O(n)
vector<int> PlusOne(vector<int> A) {
    int index = A.size();
    while (--index >= 0) {
        ++A[index];
        A[index] %= 10;     // If the current digit becomes 10, set it to 0 and carry over the 1 to the next digit.
        if (A[index] != 0)  // If the current digit is not 0 after incrementing, no need to carry over, so return the result.
            return A;
    }
    A.insert(begin(A), 1);
    return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "int_as_array_increment.cc",
                         "int_as_array_increment.tsv", &PlusOne,
                         DefaultComparator{}, param_names);
}
