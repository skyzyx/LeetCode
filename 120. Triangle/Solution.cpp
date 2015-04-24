class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int row = triangle.size();
        int col = triangle[row-1].size();
        
        int dp[col];
        for(int i = 0; i < col; i++)
            dp[i] = triangle[row-1][i];
            
        for(int i = row-2; i >= 0; i--) {
            for(int j = 0; j < triangle[i].size(); j++) {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};