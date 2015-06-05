# LeetCode #171: Excel Sheet Column Number

'''
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
'''

'''
class Solution:
    # @param s, a string
    # @return an integer
    def titleToNumber(self, s):
        res = 0;
        tmp = 0;
        for i in range(0, len(s)):
            tmp = ord(s[i]) - ord('A') + 1;
            res = res * 26 + tmp;
        return res;
'''       
        
class Solution:
    def titleToNumber(self, s):
        res = 0;
        for letter in s:
            res = res * 26 + (ord(letter) - ord('A') + 1);
        return res;
        