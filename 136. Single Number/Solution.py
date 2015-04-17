class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        res = 0;
        for element in A:
            res ^= element;
        return res;
        