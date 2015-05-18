public class Solution {
    public String longestPalindrome(String s) {
        if (s == null || s.length() == 0)
            return "";
            
        boolean[][] dp = new boolean[s.length()][s.length()];
        int maxLen = 0;
        String res = "";
        
        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = i; j < s.length(); j++) {
                if (s.charAt(i) == s.charAt(j) && (j-i <= 1 || dp[i+1][j-1] == true)) { // j-i <= 1, Like "bab"
                    dp[i][j] = true;
                    if (j-i+1 > maxLen) {
                        maxLen = j-i+1;
                        res = s.substring(i, j+1);
                    }
                }
            }
        }
        return res;
    }
}