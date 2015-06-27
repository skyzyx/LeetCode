// LeetCode #139: Word Break

/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

public class Solution {
    public boolean wordBreak(String s, Set<String> wordDict) {
        if (s == null || s.length() == 0)
            return true;
            
        int m = s.length();
        boolean[] isValid = new boolean[m+1];
        isValid[0] = true;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= i; j++) {
                if (isValid[j] == true && wordDict.contains(s.substring(j, i+1))) {
                    isValid[i+1] = true;
                    break;
                }
            }
        }
        return isValid[m];
    }
}

/*
public class Solution { // Time Limit Exceeded
    public boolean wordBreak(String s, Set<String> wordDict) {
        if (s.length() == 0)
            return true;
            
        for (int i = 0; i <= s.length(); i++) {
            String firstWord = s.substring(0, i);
            if (wordDict.contains(firstWord) && wordBreak(s.substring(i), wordDict))
                return true;
        }
        return false;
    }
}
*/