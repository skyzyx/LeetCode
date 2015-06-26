// LeetCode #115: Distinct Subsequences

/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/

public class Solution { // Time Limit Exceeded
    public int numDistinct(String s, String t) {
        if (s == null || t == null)
            return 0;
            
        if (s.length() == 0)
            return t.length() == 0? 1: 0;
            
        if (t.length() == 0)
            return 1;
            
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == t.charAt(0))
                res += numDistinct(s.substring(i+1), t.substring(1));
        }
        return res;
    }
}