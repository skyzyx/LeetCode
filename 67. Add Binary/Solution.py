class Solution:
    # @param {string} a
    # @param {string} b
    # @return {string}
    def addBinary(self, a, b):
        res = ""
        i = len(a) - 1
        j = len(b) - 1
        
        carry = 0
        while i >= 0 or j >= 0:
            if i >= 0:
                carry += int(a[i])
                i -= 1
                
            if j >= 0:
                carry += int(b[j])
                j -= 1
            
            res = str(carry % 2) + res
            carry /= 2
             
             
        if carry == 1:
            res = str(carry) + res
            
        return res
            
        