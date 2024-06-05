#include <string>

#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"
using std::string;

// O(n)
void ReverseWords(string* s) {
    std::reverse(s->begin(), s->end());
    int end = 0;
    for (int start = 0; start < s->size(); start = end + 1) {
        for (end = start; end < s->size(); ++end) {
            if ((*s)[end] == ' ')
                break;
        }
        reverse(s->begin() + start, s->begin() + end);
    }
}

string ReverseWordsWrapper(TimedExecutor& executor, string s) {
  string s_copy = s;

  executor.Run([&] { ReverseWords(&s_copy); });

  return s_copy;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "s"};
  return GenericTestMain(args, "reverse_words.cc", "reverse_words.tsv",
                         &ReverseWordsWrapper, DefaultComparator{},
                         param_names);
}
