public class Solution {
    public int maxProfit(int k, int[] prices) {
        if (prices == null || prices.length == 0)
            return 0;
            
        int maxProfit = 0;
        if (k > prices.length) {
            for (int i = 1; i < prices.length; i++)
                maxProfit += prices[i] - prices[i-1] > 0? prices[i] - prices[i-1]: 0;
            return maxProfit;
        }
        
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