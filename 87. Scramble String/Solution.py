# LeetCode #87: Scramble String

'''
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
'''

class Solution:
    # @param {string} s1
    # @param {string} s2
    # @return {boolean}
    def isScramble(self, s1, s2):
        if len(s1) != len(s2):
            return False
        if s1 == s2:
            return True
            
        t1 = ''.join(sorted(s1))
        t2 = ''.join(sorted(s2))
        if t1 != t2:
            return False
        
        for i in xrange(1, len(s1)):
            s1part1 = s1[0:i]
            s1part2 = s1[i:]
            s2part1 = s2[0:i]
            s2part2 = s2[i:]
            
            if self.isScramble(s1part1, s2part1) and self.isScramble(s1part2, s2part2):
                return True
                
            s2part1 = s2[len(s2) - i:]
            s2part2 = s2[0:len(s2) - i]
            if self.isScramble(s1part1, s2part1) and self.isScramble(s1part2, s2part2):
                return True
            
        return False