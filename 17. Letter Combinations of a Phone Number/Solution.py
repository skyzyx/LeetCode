# LeetCode #17: Letter Combination of a Phone Number

'''
Given a digit string, return all possible letter combinations that the number could represent.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
'''

class Solution:
    # @param {string} digits
    # @return {string[]}
    def letterCombinations(self, digits):
        res = []
        if digits == None or len(digits) == 0:
            return res
            
        board = [" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        cur = ""
        self.dfs(0, cur, res, digits, board)
        return res
        
    def dfs(self, index, cur, res, digits, board):
        if index == len(digits):
            res.append(str(cur))
            return
        
        s = board[int(digits[index])]
        for i in xrange(len(s)):
            cur += s[i] # NOT cur.append(s[i])
            self.dfs(index+1, cur, res, digits, board)
            cur = cur[0:-1] # Not cur.pop()
        
        
            
        