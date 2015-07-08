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

public class Solution {
    public boolean isScramble(String s1, String s2) {
        if (s1.equals(s2)) return true;
        if (s1.length() != s2.length()) return false;
        
        char[] t1 = s1.toCharArray();
        Arrays.sort(t1);
        
        char[] t2 = s2.toCharArray();
        Arrays.sort(t2);
        
        if (!String.valueOf(t1).equals(String.valueOf(t2))) return false;
        
        for (int i = 1; i < s1.length(); i++) {
            String s1part1 = s1.substring(0, i);
            String s1part2 = s1.substring(i);
            
            String s2part1 = s2.substring(0, i);
            String s2part2 = s2.substring(i);
            
            if (isScramble(s1part1, s2part1) && isScramble(s1part2, s2part2)) return true;
            
            s2part1 = s2.substring(s2.length() - i);
            s2part2 = s2.substring(0, s2.length() - i);
            
            if (isScramble(s1part1, s2part1) && isScramble(s1part2, s2part2)) return true;
        }
        return false;
    }
}