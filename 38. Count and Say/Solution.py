# LeetCode #38: Count and Say

'''
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
'''

class Solution:
    # @param {integer} n
    # @return {string}
    def countAndSay(self, n):
        if n < 1:
            return "";
            
        res = "1"
        for i in xrange(1, n):
            tmp = ""
            count = 1
            for j in range(1, len(res)):
                if res[j] == res[j-1]:
                    count += 1
                else:
                    tmp += str(count) + res[j-1]
                    count = 1
            
            tmp += str(count) + res[len(res) - 1]
            res = tmp
            
        return res