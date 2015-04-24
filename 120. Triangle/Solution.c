int minimumTotal(int **triangle, int numRows) {
    for(int i = numRows - 2; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            int min = triangle[i+1][j] < triangle[i+1][j+1]? triangle[i+1][j]: triangle[i+1][j+1];
            triangle[i][j] += min;
        }
    }
    return triangle[0][0];
}