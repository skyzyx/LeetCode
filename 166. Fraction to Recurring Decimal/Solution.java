// LeetCode #166: Fraction to Recurring Decimal

/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
*/

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