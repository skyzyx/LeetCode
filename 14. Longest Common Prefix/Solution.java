// LeetCode #14: Longest Common Prefix

/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

public class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0)
            return "";
            
        for (int i = 0; i < strs[0].length(); i++) {
            char letter = strs[0].charAt(i);
            for (int j = 1; j < strs.length; j++) {
                if (i >= strs[j].length() || letter != strs[j].charAt(i))
                    return strs[0].substring(0, i);
            }
        }
        
        return strs[0];
    }
}