#include <string>

#include "test_framework/generic_test.h"
using std::string;
string ShortestEquivalentPath(const string& path) {
    std::stack<string> dirs;
    std::stringstream stream(path);
    string dir;
    while (std::getline(stream, dir, '/')) {
        if (!dir.empty() && dir != ".") {

            dirs.emplace(dir);
        }
    }

    string answer;

    while (!dirs.empty()) {
        answer = dirs.top() + "/" + answer;
        dirs.pop();
    }

    if (!answer.empty() && answer.back() == '/')
        answer.pop_back();

    return answer;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"path"};
  return GenericTestMain(args, "directory_path_normalization.cc",
                         "directory_path_normalization.tsv",
                         &ShortestEquivalentPath, DefaultComparator{},
                         param_names);
}
