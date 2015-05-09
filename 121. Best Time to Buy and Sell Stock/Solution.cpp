class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
            
        int maxProfit = 0;
        int lowest = prices[0];
        
        for (int i = 1; i < prices.size(); i++) {
            maxProfit = max(maxProfit, prices[i] - lowest);
            lowest = min(lowest, prices[i]);
        }
        return maxProfit;
    }
};