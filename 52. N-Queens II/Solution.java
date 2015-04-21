public class Solution {
    public int totalNQueens(int n) {
        int[] res = {0};
        char[][] board = new char[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = '.';
            }
        }
        
        dfs(0, 0, 0, res, board);
        return res[0];
    }
    
    private void dfs(int i, int j, int count, int[] res, char[][] board) {
        if (count == board.length) {
            res[0] += 1;
            return;
        }
        
        for (int row = 0; row < board.length; row++) {
            if (isValid(row, j, board)) {
                board[row][j] = 'Q';
                dfs(row, j+1, count+1, res, board);
                board[row][j] = '.';
            }
        }
    }
    
    private boolean isValid(int row, int col, char[][] board) {
        for (int i = 0; i < board.length; i++)
            if (board[row][i] == 'Q' || board[i][col] == 'Q')
                return false;
                
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;
                
        for (int i = row, j = col; i < board.length && j >= 0; i++, j--)
            if (board[i][j] == 'Q')
                return false;
                
        return true;
    }
}