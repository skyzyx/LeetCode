// LeetCode #115: Distinct Subsequences

/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/

class Solution { // Time Limit Exceeded
public:
    int numDistinct(string s, string t) {
        if (s.size() == 0)
            return t.size() == 0? 1: 0;
            
        if (t.size() == 0)
            return 1;
            
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[0])
                numDistinct(s.substr(i+1), t.substr(1));
        }
        return res;
    }
};