#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
// O(n)
double BuyAndSellStockTwice(const vector<double>& prices) {
    double buy_one = std::numeric_limits<double>::max();
    double profit_one = std::numeric_limits<double>::min();
    double buy_two = std::numeric_limits<double>::max();
    double profit_two = std::numeric_limits<double>::min();
    for (int i = 0; i < prices.size(); ++i) {
        buy_one = std::min(buy_one, prices[i]);
        profit_one = std::max(profit_one, prices[i] - buy_one);
        buy_two = std::min(buy_two, prices[i] - profit_one);
        profit_two = std::max(profit_two, prices[i] - buy_two);
    }
    return profit_two;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  const vector<double> prices{3,3,5,0,0,3,1,4};
  BuyAndSellStockTwice(prices);
  return GenericTestMain(args, "buy_and_sell_stock_twice.cc",
                         "buy_and_sell_stock_twice.tsv", &BuyAndSellStockTwice,
                         DefaultComparator{}, param_names);
}
