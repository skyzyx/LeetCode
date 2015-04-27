class Solution:
    # @param digits, a list of integer digits
    # @return a list of integer digits
    def plusOne(self, digits):
        carry = 1
        for i in range(len(digits) - 1, 0, -1):
            if digits[i] + carry == 10:
                digits[i] = 0
                carry = 1
            else:
                digits[i] += carry
                return digits
        
        digits.insert(0, 1)
        return digits
        