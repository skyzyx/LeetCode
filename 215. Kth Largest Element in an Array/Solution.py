class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {integer}
    def findKthLargest(self, nums, k):
        nums.sort()
        return nums[len(nums) - k];