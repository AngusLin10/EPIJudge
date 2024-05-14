#include <vector>
#include <unordered_set>

#include "test_framework/generic_test.h"
using std::vector;
// Check if a partially filled matrix has any conflicts.
bool IsValidSudoku(const vector<vector<int>>& partial_assignment) {
    // Create a bit vector to track unique numbers in rows, columns, and sub-grids
    std::unordered_set<int> row_set[9], col_set[9], box_set[9];
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int val = partial_assignment[i][j];
            int boxIndex = (i / 3) * 3 + (j / 3);
            if (val != 0) {
                if (row_set[i].count(val) 
                    || col_set[j].count(val) 
                    || box_set[boxIndex].count(val)) 
                    return false;

                row_set[i].insert(val);
                col_set[j].insert(val);
                box_set[boxIndex].insert(val);
            }
        }
    }

    return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"partial_assignment"};
  return GenericTestMain(args, "is_valid_sudoku.cc", "is_valid_sudoku.tsv",
                         &IsValidSudoku, DefaultComparator{}, param_names);
}
