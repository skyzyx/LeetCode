# LeetCode #27: Remove Element

'''
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
'''

class Solution:
    # @param    A       a list of integers
    # @param    elem    an integer, value need to be removed
    # @return an integer
    def removeElement(self, A, elem):
        if A == None:
            return -1
        if len(A) == 0:
            return 0
        
        slow = 0;
        fast = 0;
        while fast < len(A):
            if A[fast] != elem:
                A[slow] = A[fast];
                slow += 1;
            fast += 1;
        return slow;
        