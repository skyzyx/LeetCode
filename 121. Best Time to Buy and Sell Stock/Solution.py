# LeetCode #121: Best Time to Buy and Sell Stock

'''
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
'''

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