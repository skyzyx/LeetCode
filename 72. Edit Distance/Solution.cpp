// LeetCode #72: Edit Distance

/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        int dp[m+1][n+1];
        for (int i = 0; i < m+1; i++)
            dp[i][0] = i;
        
        for (int j = 0; j < n+1; j++)
            dp[0][j] = j;
            
        for (int i = 1; i < m+1; i++) {
            for (int j = 1; j < n+1; j++) {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(min(dp[i-1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1] + 1);
            }
        }
        return dp[m][n];
        
    }
};