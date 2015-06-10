# LeetCode #205: Ismorphic Strings

'''
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
'''

class Solution:
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def isIsomorphic(self, s, t):
        if len(s) != len(t):
            return False
            
        sdict = {}
        tdict = {}
        
        for i in xrange(len(s)):
            if sdict.has_key(s[i]):
                if sdict[s[i]] != t[i]:
                    return False
                    
            if tdict.has_key(t[i]):
                if tdict[t[i]] != s[i]:
                    return False
                    
            sdict[s[i]] = t[i]
            tdict[t[i]] = s[i]
        
        return True