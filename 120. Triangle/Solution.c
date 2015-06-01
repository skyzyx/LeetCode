// LeetCode #120: Triangle

/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

int minimumTotal(int **triangle, int numRows) {
    for(int i = numRows - 2; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            int min = triangle[i+1][j] < triangle[i+1][j+1]? triangle[i+1][j]: triangle[i+1][j+1];
            triangle[i][j] += min;
        }
    }
    return triangle[0][0];
}