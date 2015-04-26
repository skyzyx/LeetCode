class Solution:
    # @param A a list of integers
    # @return nothing, sort in place
    def sortColors(self, A):
        if len(A) <= 1:
            return
            
        i = 0
        j = len(A) - 1
        zeroIndex = 0
        
        while i <= j:
            if A[i] == 0:
                self.swap(A, i, zeroIndex)
                i += 1
                zeroIndex += 1
            elif A[i] == 2:
                self.swap(A, i, j)
                j -= 1
            else:
                i += 1
                
        return
    
    def swap(self, A, i, j):
        temp = A[i]
        A[i] = A[j]
        A[j] = temp
            
        