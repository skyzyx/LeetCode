# LeetCode #122: Best Time to Buy and Sell Stock II

'''
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
'''

class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        if prices == None or len(prices) < 2:
            return 0
            
        profit = 0
        for i in range(1, len(prices)):
            if (prices[i] - prices[i-1]) > 0:
                profit += prices[i] - prices[i-1]
        return profit
        