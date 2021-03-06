// LeetCode #28: Implement strStr()

/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

public class Solution {
    public int strStr(String haystack, String needle) {
        int hlen = haystack.length();
        int nlen = needle.length();
        
        for (int i = 0; i + nlen <= hlen; i++) {
            if (haystack.substring(i, i+nlen).equals(needle))
                return i;
        }
        return -1;
    }
}