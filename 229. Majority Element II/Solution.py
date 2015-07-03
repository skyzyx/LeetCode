# LeetCode #229: Majority Element II

'''
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

Hint:

How many majority elements could it possibly have?
Do you have a better hint? Suggest it!
'''

class Solution:
    # @param {integer[]} nums
    # @return {integer[]}
    def majorityElement(self, nums):
        res = []
        if nums is None or len(nums) == 0:
            return res
            
        n1, c1, n2, c2 = 0, 0, 0, 0
        
        for num in nums:
            if c1 == 0:
                n1 = num
            if c2 == 0:
                n2 = num
                
            if num == n1:
                c1 += 1
            elif num == n2:
                c2 += 1
            else:
                c1 -= 1
                c2 -= 1
                
        c1 = 0
        c2 = 0
        for num in nums:
            if num == n1:
                c1 += 1
            elif num == n2:
                c2 += 1
                
        if c1 > len(nums) / 3:
            res.append(n1)
        if c2 > len(nums) / 3:
            res.append(n2)
            
        return res