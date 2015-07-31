// LeetCode #36: Valid Sudoku

/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. 
Only the filled cells need to be validated.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() != 9 || board[0].size() != 9)
            return false;
            
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool gri[9][9] = {false};
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                    
                int k = board[i][j] - '1';
                if (row[i][k] || col[j][k] || gri[i/3*3 + j/3][k])
                    return false;
                    
                row[i][k] = col[j][k] = gri[i/3*3 + j/3][k] = true;
            }
        }
        return true;
    }
};