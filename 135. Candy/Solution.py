# LeetCode #135: Candy

'''
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
'''

class Solution:
    # @param {integer[]} ratings
    # @return {integer}
    def candy(self, ratings):
        if len(ratings) == 0:
            return 0
            
        res = [1] * len(ratings)
        for i in xrange(1, len(ratings)):
            if ratings[i] > ratings[i-1]:
                res[i] = res[i-1] + 1
                
        candyNums = 0
        for i in xrange(len(ratings) - 2, -1, -1):
            if ratings[i] > ratings[i+1] and res[i] <= res[i+1]:
                res[i] = res[i+1] + 1
                
            candyNums += res[i]
            
        candyNums += res[len(res) - 1]
        return candyNums
        