#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
// O(n^2)
void RotateMatrix(vector<vector<int>>* square_matrix_ptr) {
    vector<vector<int>>& result = *square_matrix_ptr;
    for (int i = 0; i < result.size(); ++i) {
        for (int j = i + 1; j < result[0].size(); ++j) {
            std::swap(result[i][j], result[j][i]);
        }
        std::reverse(result[i].begin(), result[i].end());
    }
}
vector<vector<int>> RotateMatrixWrapper(vector<vector<int>> square_matrix) {
  RotateMatrix(&square_matrix);
  return square_matrix;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"square_matrix"};
  return GenericTestMain(args, "matrix_rotation.cc", "matrix_rotation.tsv",
                         &RotateMatrixWrapper, DefaultComparator{},
                         param_names);
}
