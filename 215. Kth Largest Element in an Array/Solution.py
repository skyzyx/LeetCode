# LeetCode #215: Kth Largest Element in an Array

'''
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
'''

class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {integer}
    def findKthLargest(self, nums, k): # In Python, this is a MinHeap
        h = []
        for num in nums:
            heapq.heappush(h, num)
            
        while len(h) > k:
            heapq.heappop(h)
            
        return h[0]

'''
class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {integer}
    def findKthLargest(self, nums, k):
        nums.sort()
        return nums[len(nums) - k];
'''