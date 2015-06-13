// LeetCode #17: Letter Combination of a Phone Number

/*
Given a digit string, return all possible letter combinations that the number could represent.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0)
            return res;
            
        string board[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string sb;
        dfs(0, sb, digits, board, res);
        return res;
    }
    
private:
    void dfs(int index, string sb, string digits, string board[], vector<string> &res) {
        if (index == digits.size()) {
            res.push_back(sb);
            return;
        }
        
        string letters = board[digits[index] - '0'];
        for (int i = 0; i < letters.size(); i++) {
            sb.push_back(letters[i]);
            dfs(index+1, sb, digits, board, res);
            sb.pop_back();
        }
    }
};