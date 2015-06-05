# LeetCode #169: Majority Element

'''
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
'''

class Solution:
    def majorityElement(self, num):
        dic = {} # dic = dict()
        for i in xrange(len(num)):
            if dic.has_key(num[i]):
                dic[num[i]] += 1
            else:
                dic[num[i]] = 0
                
            if dic[num[i]] >= len(num) / 2:
                return num[i]

"""
class Solution:
    # @param num, a list of integers
    # @return an integer
    def majorityElement(self, num):
        majorIndex = 0
        majorCount = 1
        
        for i in range(1, len(num)):
            if num[majorIndex] == num[i]:
                majorCount += 1
            else:
                majorCount -= 1
                
            if majorCount == 0:
                majorCount = 1
                majorIndex = i
                
        return num[majorIndex]
"""     