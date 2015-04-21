public class Solution {
    public List<String[]> solveNQueens(int n) {
        List<String[]> res = new ArrayList<String[]>();
        char[][] board = new char[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = '.';
            }
        }
        
        dfs(0, 0, 0, board, res);
        return res;
    }
    
    private void dfs(int row, int col, int count, char[][] board, List<String[]> res) {
        if (count == board.length) {
            String[] tmp = new String[count];
            for (int k = 0; k < count; k++) {
                tmp[k] = new String(board[k]);
            }
            res.add(tmp);
            return;
        }
        
        for (int i = 0; i < board.length; i++) {
            if (isValid(i, col, board)) {
                board[i][col] = 'Q';
                dfs(i, col+1, count+1, board, res);
                board[i][col] = '.';
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