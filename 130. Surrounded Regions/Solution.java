public class Solution {
    private Queue<Integer> que = new LinkedList<Integer>();
    
    public void solve(char[][] board) {
        if (board == null || board.length == 0 || board[0].length == 0)
            return;
            
        int m = board.length;
        int n = board[0].length;
        
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                bfs(board, i, 0);
            if (board[i][n-1] == 'O')
                bfs(board, i, n-1);
        }
        
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                bfs(board, 0, j);
            if (board[m-1][j] == 'O')
                bfs(board, m-1, j);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
    
    private void bfs(char[][] board, int i, int j) {
        int n = board[0].length;
        flood(board, i, j);
        
        while (!que.isEmpty()) {
            int cur = que.poll();
            int x = cur / n;
            int y = cur % n;
            
            flood(board, x-1, y);
            flood(board, x+1, y);
            flood(board, x, y-1);
            flood(board, x, y+1);
        }
    }
    
    private void flood(char[][] board, int i, int j) {
        int m = board.length;
        int n = board[0].length;
        
        if (i < 0 || j < 0 || i >= m || j >= n)
            return;
            
        if (board[i][j] != 'O')
            return;

        que.offer(i * n + j);
        board[i][j] = '#';
        
    }
}

/*
public class Solution {
    public void solve(char[][] board) {
        if (board == null || board.length == 0 || board[0].length == 0)
            return;
            
        int m = board.length;
        int n = board[0].length;
        
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);
            if (board[i][n-1] == 'O')
                dfs(board, i, n-1);
        }
        
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j);
            if (board[m-1][j] == 'O')
                dfs(board, m-1, j);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
    
    private void dfs(char[][] board, int i, int j) {
        if (i < 0 || j < 0 || i >= board.length || j >= board[0].length)
            return;
        
        if (board[i][j] != 'O')
            return;
            
        board[i][j] = '#';
        dfs(board, i-1, j);
        dfs(board, i+1, j);
        dfs(board, i, j-1);
        dfs(board, i, j+1);
    }
}

*/