// LeetCode #36: Valid Sudoku

/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. 
Only the filled cells need to be validated.
*/

public class Solution {
    public boolean isValidSudoku(char[][] board) {
        if (board == null || board.length != 9 || board[0].length != 9)
            return false;
        
        boolean[][] flagRow = new boolean[9][9];
        boolean[][] flagCol = new boolean[9][9];
        boolean[][] flagGri = new boolean[9][9];
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                int k = board[i][j] - '1';
                if (flagRow[i][k] || flagCol[k][j] || flagGri[i/3*3+j/3][k])
                    return false;
                flagRow[i][k] = flagCol[k][j] = flagGri[i/3*3+j/3][k] = true;
            }
        }
        return true;
    }
}