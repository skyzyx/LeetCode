void dfs(char** grid, int i, int j, int numRows, int numColumns) {
    if (i < 0 || j < 0 || i >= numRows || j >= numColumns)
        return;
    if (grid[i][j] != '1')
        return;
            
    grid[i][j] = '-';
        
    dfs(grid, i, j-1, numRows, numColumns);
    dfs(grid, i, j+1, numRows, numColumns);
    dfs(grid, i-1, j, numRows, numColumns);
    dfs(grid, i+1, j, numRows, numColumns);
}

int numIslands(char **grid, int numRows, int numColumns) {
    if (numRows == 0 || numColumns == 0)
            return 0;
            
        int res = 0;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numColumns; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    dfs(grid, i, j, numRows, numColumns);
                }
            }
        }
        return res;
}
