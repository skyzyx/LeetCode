# LeetCode #128: Longest Consecutive Sequence

'''
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
'''

class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def longestConsecutive(self, nums):
        dic = {num: False for num in nums}
        maxLen = 0
        
        for num in nums:
            if dic[num] == False:
                count = 1
                left = num - 1
                right = num + 1
                
                while left in dic and dic[left] == False: # Without "left in dic", an error occured, KeyError: -1
                    dic[left] = True # Means visited.
                    count += 1
                    left -= 1
                    
                while right in dic and dic[right] == False:
                    dic[right] = True
                    count += 1
                    right += 1
                
                maxLen = max(maxLen, count)
                
        return maxLen
                    