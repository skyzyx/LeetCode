class Solution:
    # @return a string
    def intToRoman(self, num):
        symbol = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]; # Not {"M", "CM"...}
        value = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
        
        res = "";
        for i in range(0, len(value)):
            while (num >= value[i]):
                num -= value[i];
                res += symbol[i];
        return res;
        