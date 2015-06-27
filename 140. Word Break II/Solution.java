// LeetCode #140: Word Break II

/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/

public class Solution {
    public List<String> wordBreak(String s, Set<String> wordDict) {
        List<String> res = new ArrayList<String>();
        if (s == null || s.length() == 0)
            return res;
            
        int m = s.length();
        boolean[] isValid = new boolean[m+1];
        isValid[0] = true;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= i; j++) {
                if (isValid[j] && wordDict.contains(s.substring(j, i+1))) {
                    isValid[i+1] = true;
                    break;
                }
            }
        }
        
        if (isValid[m] == false)
            return res;
            
        dfs("", res, s, wordDict);
        return res;
    }
    
    private void dfs(String t, List<String> res, String s, Set<String> wordDict) {
        if (s.length() == 0) {
            res.add(t);
            return;
        }
        
        for (int i = 0; i <= s.length(); i++) {
            String word = s.substring(0, i);
            if (wordDict.contains(word)) {
                String cur = t.length() == 0? word: t + " " + word;
                dfs(cur, res, s.substring(i), wordDict);
            }
        }
    }
}