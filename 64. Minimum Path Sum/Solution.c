int returnMin(int a, int b) {
    return a < b? a: b;
}

int minPathSum(int **grid, int nRows, int nCols) {
    if (nRows == 0 || nCols == 0)
        return 0;
        
    int dp[nRows][nCols];
    dp[0][0] = grid[0][0];
    
    for (int i = 1; i < nCols; i++)
        dp[0][i] = dp[0][i-1] + grid[0][i];
        
    for (int j = 1; j < nRows; j++)
        dp[j][0] = dp[j-1][0] + grid[j][0];
        
    for (int i = 1; i < nRows; i++) {
        for (int j = 1; j < nCols; j++) {
            dp[i][j] = returnMin(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }
    
    return dp[nRows-1][nCols-1];
}