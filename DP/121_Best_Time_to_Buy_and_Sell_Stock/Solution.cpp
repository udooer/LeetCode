// 121. Best Time to Buy and Sell Stock
/*
Thought:
DP
1. get an array from the botton the get the maxprice

Time complexity: O(n)
Space complexity: O(n)
*/
#include <vector>

class Solution_01 {
public:
    int maxProfit(vector<int>& prices) {
        std::vector<int> maxPrices(prices.size(), 0);

        for (int i = prices.size() - 2; i > -1; i--) 
        {
            maxPrices[i] = max(prices[i], maxPrices[i + 1]);
        }

        int maxPrice = 0;
        for (int i = 0; i < prices.size() - 2; i++) 
        {
            maxPrice = max(maxPrice, maxPrices[i] - prices[i]);
        }

        return maxPrice;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) 
        {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};
