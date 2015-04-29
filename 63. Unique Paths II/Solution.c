int uniquePathsWithObstacles(int **obstacleGrid, int m, int n){
    int dp[m][n];
        
    for (int j = 0; j < n; j++) {
        if (obstacleGrid[0][j] == 0) {
            dp[0][j] = 1;
        } else {
            while (j < n) {
                dp[0][j] = 0;
                j += 1;
            }
        }
    }
        
    for (int i = 0; i < m; i++) {
        if (obstacleGrid[i][0] == 0) {
            dp[i][0] = 1;
        } else {
            while (i < m) {
                dp[i][0] = 0;
                i += 1;
            }
        }
    }
        
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 0) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            } else {
                dp[i][j] = 0;
            }
        }
    }
        
    return dp[m-1][n-1];
}