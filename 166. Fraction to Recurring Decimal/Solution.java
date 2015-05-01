public class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
            
        String res = new String();
        if (numerator < 0 ^ denominator < 0)
            res += "-";
            
        long n = numerator;
        long d = denominator;
        
        n = Math.abs(n);
        d = Math.abs(d);
        
        long ans = n / d;
        res += String.valueOf(ans);
        long remainder = (n % d) * 10;
        if (remainder == 0)
            return res;
            
        res += ".";
        Map<Long, Integer> map = new HashMap<Long, Integer>();
        while (remainder != 0) {
            if (map.containsKey(remainder)) {
                int pos = map.get(remainder);
                String left = res.substring(0, pos);
                String right = res.substring(pos);
                res = left + "(" + right + ")";
                return res;
            }
            
            map.put(remainder, res.length());
            res += String.valueOf(remainder / d);
            remainder = (remainder % d) * 10;
        }
        return res;
    }
}