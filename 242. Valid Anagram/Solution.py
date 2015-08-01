# LeetCode #242: Valid Anagram

'''
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
'''

class Solution:
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def isAnagram(self, s, t):
        slist = list(s)
        tlist = list(t)
        
        slist.sort()
        tlist.sort()
        return str(slist) == str(tlist) # slist == tlist

'''
class Solution:
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False
            
        myDict = {}
        for i in xrange(len(s)):
            if s[i] not in myDict:
                myDict[s[i]] = 1
            else:
                myDict[s[i]] += 1
                
        for i in xrange(len(t)):
            if t[i] not in myDict:
                return False
            else:
                if myDict[t[i]] == 0:
                    return False
                else:
                    myDict[t[i]] -= 1
                    
        return True
'''