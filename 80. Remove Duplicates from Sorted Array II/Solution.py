# LeetCode #80: Remove Duplicates from Sorted Array II

'''
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
'''

class Solution:
    # @param A a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        if A == None:
            return -1
        if len(A) < 3:
            return len(A)
            
        slow = 1
        fast = 2
        while fast < len(A):
            if A[fast] == A[slow] and A[fast] == A[slow - 1]:
                fast += 1
            else:
                slow += 1
                A[slow] = A[fast]
                fast += 1
        return slow + 1
        