# LeetCode #164: Maximum Gap

'''
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
'''

class Solution:
    # @param num, a list of integer
    # @return an integer
    def maximumGap(self, num):
        num.sort()
        maxGap = 0
        for i in range(1, len(num)):
            maxGap = max(maxGap, num[i] - num[i-1])
        return maxGap
        