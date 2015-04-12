class Solution:
    # @param a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        if A == None:
            return -1
            
        if len(A) < 2:
            return len(A)
            
        slow = 1
        for fast in range(1, len(A)):
            if A[fast] != A[fast-1]:
                A[slow] = A[fast]
                slow += 1
        return slow
        