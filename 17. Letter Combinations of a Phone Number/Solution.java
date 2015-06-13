// LeetCode #17: Letter Combination of a Phone Number

/*
Given a digit string, return all possible letter combinations that the number could represent.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

public class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<String>();
        if (digits == null || digits.length() == 0)
            return res;
        
        String[] board = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        StringBuilder sb = new StringBuilder();
        dfs(0, sb, digits, board, res);
        return res;
    }
    
    private void dfs(int index, StringBuilder sb, String digits, String[] board, List<String> res) {
        if (index == digits.length()) {
            res.add(sb.toString());
            return;
        }
        
        String s = board[digits.charAt(index) - '0'];
        for (int i = 0; i < s.length(); i++) {
            sb.append(s.charAt(i));
            dfs(index+1, sb, digits, board, res);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}