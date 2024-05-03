#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
// O(n)
double BuyAndSellStockOnce(const vector<double>& prices) {
    double min_price = std::numeric_limits<double>::max();
    double profit = 0.0;
    for (int i = 0; i < prices.size(); ++i) {
        min_price = std::min(min_price, prices[i]);
        profit = std::max(profit, prices[i] - min_price);
    }

    return profit;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}
