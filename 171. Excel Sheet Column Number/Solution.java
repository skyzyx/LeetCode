public class Solution {
    public int titleToNumber(String s) {
        if (s == null || s.length() == 0)
            return 0;
        
        int res = 0;
        int tmp = 0;
        for (int i = 0; i < s.length(); i++) {
            tmp = s.charAt(i) - 'A' + 1;
            res = res * 26 + tmp;
        }
        return res;
    }
}