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
        