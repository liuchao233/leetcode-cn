#include <vector>
#include <algroithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int maxProfit = 0, minPrice = prices[0];
    
        for (int i = 1; i < len; ++i) {
            int price = prices[i];
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};