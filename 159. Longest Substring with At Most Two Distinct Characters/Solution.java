public class Solution {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        int i = 0;
        int j = -1;
        int maxLen = 0;
        
        for (int k = 1; k < s.length(); k++) {
            if (s.charAt(k) == s.charAt(k-1))
                continue;
            if (j >= 0 && s.charAt(k) != s.charAt(j)) {
                maxLen = Math.max(maxLen, k-i);
                i = j+1;
            }
            j = k-1;
        }
        return Math.max(s.length() - i, maxLen);
    }
}