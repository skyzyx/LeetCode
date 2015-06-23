# LeetCode #219: Contains Duplicate II

# Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.

class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {boolean}
    def containsNearbyDuplicate(self, nums, k):
        if nums == None or len(nums) < 2:
            return False
            
        mydic = {}
        for i in xrange(len(nums)):
            if not mydic.has_key(nums[i]):
                mydic[nums[i]] = i
            else:
                if i - mydic[nums[i]] <= k:
                    return True
                    
                mydic[nums[i]] = i
                
        return False
