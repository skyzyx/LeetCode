# LeetCode #139: Word Break

'''
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
'''

class Solution:
    def wordBreak(self, s, wordDict):
        if len(s) == 0:
            return true
            
        m = len(s)
        isValid = [False for i in xrange(m+1)]
        isValid[0] = True
        
        for i in xrange(m):
            for j in xrange(i+1):
                if isValid[j] == True and s[j:i+1] in wordDict:
                    isValid[i+1] = True
                    
        return isValid[m]

'''
class Solution: # Time Limit Exceeded
    # @param s, a string
    # @param wordDict, a set<string>
    # @return a boolean
    def wordBreak(self, s, wordDict):
        if len(s) == 0:
            return True
            
        for i in xrange(len(s) + 1):
            firstWord = s[0:i]
            if firstWord in wordDict:
                self.wordBreak(s[i:], wordDict)
                
        return False
'''