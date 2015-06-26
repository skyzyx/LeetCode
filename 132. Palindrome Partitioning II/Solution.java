// LeetCode #132: Palindrome Partitioning II

/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

public class Solution {
    public int minCut(String s) {
        int m = s.length();
        boolean[][] isPalindrome = new boolean[m][m];
        
        for (int i = m-1; i >= 0; i--) {
            for (int j = i; j < m; j++) {
                if (s.charAt(i) == s.charAt(j) && (j - i <= 1 || isPalindrome[i+1][j-1] == true))
                    isPalindrome[i][j] = true;
            }
        }
        
        int[] cut = new int[m+1];
        for (int i = m; i >= 0; i--)
            cut[i] = m - i - 1;
            
        for (int i = m-1; i >= 0; i--) {
            for (int j = i; j < m; j++) {
                if (isPalindrome[i][j] == true)
                    cut[i] = Math.min(cut[i], cut[j+1] + 1);
            }
        }
        return cut[0];
    }
}