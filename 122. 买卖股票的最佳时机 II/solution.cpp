#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int income = 0;
        decltype(prices.size()) buy = 0, sell = 1;

        for (; sell < prices.size(); ++sell) {
            if (prices[sell] < prices[sell - 1]) {
                // sell all stocks
                income += (prices[sell - 1] - prices[buy]);
                // buy today
                buy = sell;
            }
        }

        income += (prices[sell - 1] - prices[buy]);
        return income;
    }
};

int main() {
    Solution solution = Solution();

    vector<int> prices1{7,1,5,3,6,4};
    cout << solution.maxProfit(prices1) << endl;

    return 0;
}