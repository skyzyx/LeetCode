// LeetCode #79: Word Search

/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

public class Solution {
    public boolean exist(char[][] board, String word) {
        if (word == null || word.length() == 0) return true;
        if (board == null || board.length == 0) return false;
            
        int m = board.length;
        int n = board[0].length;
        boolean[][] visited = new boolean[m][n];
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(board, visited, word, 0, i, j))
                    return true;
        return false;
    }
    
    private boolean dfs(char[][] board, boolean[][] visited, String word, int k, int i, int j) {
        if (k == word.length())
            return true;
            
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || visited[i][j] == true || board[i][j] != word.charAt(k))
            return false;
            
        visited[i][j] = true;
        boolean res = dfs(board, visited, word, k+1, i-1, j) || 
                      dfs(board, visited, word, k+1, i+1, j) || 
                      dfs(board, visited, word, k+1, i, j-1) || 
                      dfs(board, visited, word, k+1, i, j+1);
        visited[i][j] = false;
        return res;
    }
}