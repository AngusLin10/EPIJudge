#include <iterator>
#include <vector>
#include <algorithm>

#include "test_framework/generic_test.h"
using std::vector;
vector<int>
ExamineBuildingsWithSunset(vector<int>::const_iterator sequence_begin,
                           const vector<int>::const_iterator &sequence_end)
{
    std::vector<int> buildings_with_view; // Stores indices of buildings with sunset view
    int index = 0; // Keeps track of current building index

    for (auto it = sequence_begin; it != sequence_end; ++it, ++index) {
        while (!buildings_with_view.empty() && *it >= *(sequence_begin + buildings_with_view.back()))
            buildings_with_view.pop_back();
            
        buildings_with_view.push_back(index);
    }
    std::reverse(buildings_with_view.begin(), buildings_with_view.end());

    return buildings_with_view;
}

vector<int> ExamineBuildingsWithSunsetWrapper(const vector<int> &sequence)
{
  return ExamineBuildingsWithSunset(cbegin(sequence), cend(sequence));
}

int main(int argc, char *argv[])
{
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sequence"};
  return GenericTestMain(args, "sunset_view.cc", "sunset_view.tsv",
                         &ExamineBuildingsWithSunsetWrapper,
                         DefaultComparator{}, param_names);
}
