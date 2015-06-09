# LeetCode #88: Merge Sorted Array

'''
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
'''

class Solution:
    # @param A  a list of integers
    # @param m  an integer, length of A
    # @param B  a list of integers
    # @param n  an integer, length of B
    # @return nothing(void)
    def merge(self, A, m, B, n):
        i = m - 1
        j = n - 1
        k = m + n - 1
        
        while i >= 0 and j >= 0:
            if A[i] >= B[j]:
                A[k] = A[i]
                i -= 1
            else:
                A[k] = B[j]
                j -= 1
            k -= 1
            
        while j >= 0:
            A[k] = B[j]
            k -= 1
            j -= 1
            
        return
        