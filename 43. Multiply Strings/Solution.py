class Solution:
    # @param {string} num1
    # @param {string} num2
    # @return {string}
    def multiply(self, num1, num2):
        if len(num1) == 0 or len(num2) == 0:
            return ""
            
        num1 = num1[::-1]
        num2 = num2[::-1]
        
        size = len(num1) + len(num2)
        data = [0] * size
        
        for i in xrange(len(num1)):
            for j in xrange(len(num2)):
                data[i+j] = data[i+j] + int(num1[i]) * int(num2[j]) # Not ord(num1[i]) * ord(num2[j])
            
        digit = 0
        carry = 0
        res = ""
        for i in xrange(size):
            digit = data[i] % 10
            carry = data[i] / 10
            
            res = str(digit) + res # Not res.insert(0, chr(digit))
            
            if i < size - 1:
                data[i+1] += carry
                
        while res[0] == '0' and len(res) > 1:
            res = res[1:]
                
        return res