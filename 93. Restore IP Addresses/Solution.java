public class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<String>();
        if (s == null || s.length() < 4 || s.length() > 12)
            return res;
            
        dfs(s, "", res, 0);
        return res;
    }
    
    private void dfs(String s, String tmp, List<String> res, int count) {
        if (count == 3 && isValid(s)) {
            res.add(tmp + s);
            return;
        }
        
        for (int i = 1; i < 4 && i < s.length(); i++) {
            String substr = s.substring(0, i);
            if (isValid(substr))
                dfs(s.substring(i), tmp + substr + ".", res, count+1);
        }
    }
    
    private boolean isValid(String s) {
        if (s == null || s.length() == 0)
            return false;
        if (s.charAt(0) == '0')
            return s.equals("0");
        int num = Integer.valueOf(s);
        return num <= 255 && num > 0;
    }
}