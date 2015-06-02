// LeetCode #131: Palindrome Partitioning

/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/

public class Solution {
    public ArrayList<ArrayList<String>> partition(String s) {
        ArrayList<ArrayList<String>> res = new ArrayList<ArrayList<String>>();
        if (s == null || s.length() == 0)
            return res;
            
        ArrayList<String> cur = new ArrayList<String>();
        dfs(s, cur, res);
        return res;
    }
    
    private void dfs(String s, ArrayList<String> cur, ArrayList<ArrayList<String>> res) {
        if (s.length() == 0) {
            res.add(new ArrayList<String>(cur));
            return;
        }
        
        // int len = s.length();
        /*
        Input:  "a"
        Output: []
        Expected:   [["a"]]
        */
        
        for (int i = 1; i <= s.length(); i++) { // NOT i < len
            String subStr = s.substring(0, i);
            if (isPalindrome(subStr)) {
                cur.add(subStr);
                dfs(s.substring(i), cur, res);
                cur.remove(cur.size() - 1);
            }
        }
    }
    
    private boolean isPalindrome(String s) {
        if (s == null)
            return false;
        
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            if (s.charAt(l) != s.charAt(r))
                return false;
            l++;
            r--;
        }
        return true;
    }
}