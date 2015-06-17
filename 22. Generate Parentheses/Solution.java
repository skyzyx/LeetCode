// LeetCode #22: Generate Parentheses

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

public class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<String>();
        if (n <= 0)
            return res;
            
        res.add("()");
        
        for (int i = 1; i < n; i++) {
            ArrayList<String> tmp = new ArrayList<String>();
            for (String word: res) {
                for (int j = 0; j <= word.length(); j++) {
                    String s = word.substring(0, j) + "()" + word.substring(j);
                    if (!tmp.contains(s))
                        tmp.add(s);
                }
            }
            res = new ArrayList<String>(tmp);
        }
        return res;
    }
}