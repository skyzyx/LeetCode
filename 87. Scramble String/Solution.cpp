// LeetCode #87: Scramble String

/*
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
*/

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        
        string t1 = s1,t2 = s2;
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if (t1 != t2) return false;
        
        for (int i = 1; i < s1.size(); i++) {
            string s1part1 = s1.substr(0,i);
            string s1part2 = s1.substr(i);
            string s2part1 = s2.substr(0,i);
            string s2part2 = s2.substr(i);
            if (isScramble(s1part1,s2part1) && isScramble(s1part2,s2part2)) 
                return true;

            s2part1 = s2.substr(s2.size() - i);
            s2part2 = s2.substr(0,s2.size() - i);
            if (isScramble(s1part1, s2part1) && isScramble(s1part2,s2part2)) 
                return true;
        }
        return false;
    }
};