public class Solution {
    public int numDecodings(String s) {
        if (s == null || s.length() == 0)
            return 0;
            
        int[] num = new int[s.length() + 1];
        num[0] = 1;
        num[1] = s.charAt(0) != '0'? 1: 0;
        
        for (int i = 2; i <= s.length(); i++) {
            if (s.charAt(i-1) != '0')
                num[i] = num[i-1];
                
            int twoDigits = (s.charAt(i-2) - '0') * 10 + (s.charAt(i-1) - '0');
            if (twoDigits >= 10 && twoDigits <= 26)
                num[i] += num[i-2];
        }
        return num[s.length()];
    }
}