public class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length < 2)
            return 0;
            
        int maxProfit = 0;
        int lowest = prices[0];
        for (int i = 1; i < prices.length; i++) {
            maxProfit = Math.max(maxProfit, prices[i] - lowest);
            lowest = Math.min(lowest, prices[i]);
        }
        return maxProfit;
    }
}