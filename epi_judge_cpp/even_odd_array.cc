#include <set>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

void EvenOdd(std::vector<int>* A_ptr) {
    std::vector<int>& result = *A_ptr;
    int even_index = 0;
    int odd_index = result.size() - 1;
    while (even_index < odd_index) {
        if (result[even_index] % 2 == 0) {
            ++even_index;
        }
        else {
            std::swap(result[even_index], result[odd_index]);
            --odd_index;
        }
    }
}

void EvenOddWrapper(TimedExecutor& executor, std::vector<int> A) {
  std::multiset<int> before(begin(A), end(A));

  executor.Run([&] { EvenOdd(&A); });

  bool in_odd = false;
  for (int a : A) {
    if (a % 2 == 0) {
      if (in_odd) {
        throw TestFailure("Even elements appear in odd part");
      }
    } else {
      in_odd = true;
    }
  }

  std::multiset<int> after(begin(A), end(A));
  if (before != after) {
    throw TestFailure("Elements mismatch");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "A"};
  return GenericTestMain(args, "even_odd_array.cc", "even_odd_array.tsv",
                         &EvenOddWrapper, DefaultComparator{}, param_names);
}
