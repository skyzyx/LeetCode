class Solution:
    # @param {integer[]} prices
    # @return {integer}
    def maxProfit(self, prices):
        if prices == None or len(prices) < 2:
            return 0;
            
        maxProfit = 0
        lowest = prices[0]
        for i in xrange(1, len(prices)):
            maxProfit = max(maxProfit, prices[i] - lowest)
            lowest = min(lowest, prices[i])
            
        return maxProfit