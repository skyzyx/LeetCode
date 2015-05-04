public class Solution {
    public boolean isOneEditDistance(String s, String t) {
        if (s == null || t == null)
            return false;
            
        int slen = s.length();
        int tlen = t.length();
        if (slen > tlen)
            return isOneEditDistance(t, s);
            
        if (tlen - slen > 1)
            return false;
            
        if (slen == tlen) {
            int diff = 0;
            for (int i = 0; i < slen; i++) {
                if (s.charAt(i) != t.charAt(i)) {
                    diff++;
                }
            }
            return diff == 1;
        }
        
        int index = 0; 
        for (; index < slen; index++) {
            if (s.charAt(index) != t.charAt(index))
                break;
        }
        
        StringBuilder sb = new StringBuilder(t);
        sb.deleteCharAt(index);
        return s.equals(sb.toString());
    }
}