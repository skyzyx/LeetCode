// LeetCode #5: Longest Palindromic Substring

/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0)
            return s;
        
        int maxLen = 0;
        string res = "";
        bool dp[s.size()][s.size()] = {false};
        
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j] && (j - i <= 1 || dp[i+1][j-1] == true)) {
                    dp[i][j] = true;
                    if (j-i+1 > maxLen) {
                        maxLen = j-i+1;
                        res = s.substr(i, j-i+1);
                    }
                }
            }
        }
        return res;
    }
};