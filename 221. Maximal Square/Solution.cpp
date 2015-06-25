// LeetCode #221: Maximal Square

/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 4.
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0)
            return 0;
            
        int dp[matrix.size()][matrix[0].size()] = {0};
        int maxLen = 0;
            
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (i > 0 && j > 0 && matrix[i][j] == '1')
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                else
                    dp[i][j] = matrix[i][j] - '0'; // Did not work: dp[i][j] = (int)matrix[i][j];
                    
                maxLen = max(maxLen, dp[i][j]);
            }
        }
        return maxLen * maxLen;
    }
};