// LeetCode #97: Interleaving String

/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();
        
        if (l1 + l2 != l3) return false;
        
        bool dp[l1+1][l2+1] = {false};
        dp[0][0] = true;
        
        for (int i = 1; i <= l1; i++) {
            dp[i][0] = s1[i-1] == s3[i-1];
            if (!dp[i][0]) break;
        }
        
        for (int j = 1; j <= l2; j++) {
            dp[0][j] = s2[j-1] == s3[j-1];
            if (!dp[0][j]) break;
        }
        
        int k = 0;
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                k = i+j-1;
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[k]) || (dp[i][j-1] && s2[j-1] == s3[k]);
            }
        }
        return dp[l1][l2];
    }
};