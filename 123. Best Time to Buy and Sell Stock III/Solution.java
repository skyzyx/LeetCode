// LeetCode #123: Best Time to Buy and Sell Stock III

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

public class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length < 2)
            return 0;
            
        int maxProfit = 0;
        int k = 2;
        
        int[][] local = new int[prices.length][k+1];
        int[][] global = new int[prices.length][k+1];
        for (int i = 1; i < prices.length; i++) {
            int localProfit = prices[i] - prices[i-1];
            for (int j = 1; j < k+1; j++) {
                local[i][j] = Math.max(global[i-1][j-1] + Math.max(0, localProfit), local[i-1][j] + localProfit);
                global[i][j] = Math.max(global[i-1][j], local[i][j]);
            }
        }
        return global[prices.length-1][k];
    }
}
/*
public class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length < 2)
            return 0;
            
        int len = prices.length;
        int[] max_profit1 = new int[len];
        int[] max_profit2 = new int[len];
        
        int min_price = prices[0];
        for (int i = 1; i < len; i++) {
            max_profit1[i] = Math.max(max_profit1[i-1], prices[i] - min_price);
            min_price = Math.min(min_price, prices[i]);
        }
        
        int max_price = prices[len-1];
        for (int i = len-2; i >= 0; i--) {
            max_profit2[i] = Math.max(max_profit2[i+1], max_price - prices[i]);
            max_price = Math.max(max_price, prices[i]);
        }
        
        int profit = 0;
        for (int i = 0; i < len; i++) {
            profit = Math.max(profit, max_profit1[i] + max_profit2[i]);
        }
        return profit;
    }
}
*/