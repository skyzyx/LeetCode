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