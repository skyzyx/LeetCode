// LeetCode #123: Best Time to Buy and Sell Stock III

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
            
        int foo[prices.size()];
        int bar[prices.size()];
        
        foo[0] = 0;
        int lowest = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            foo[i] = max(foo[i-1], prices[i] - lowest);
            lowest = min(lowest, prices[i]);
        }
        
        bar[prices.size() - 1] = 0;
        int highest = prices[prices.size() - 1];
        for (int i = prices.size() - 2; i >= 0; i--) {
            bar[i] = max(bar[i+1], highest - prices[i]);
            highest = max(highest, prices[i]);
        }
        
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++)
            maxProfit = max(maxProfit, foo[i] + bar[i]);
        return maxProfit;
    }
};