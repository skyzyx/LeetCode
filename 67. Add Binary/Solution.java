// LeetCode #67: Add Binary

/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

public class Solution {
    public String addBinary(String a, String b) {
        if (a == null || b == null)
            return null;
        
        int i = a.length() - 1;
        int j = b.length() - 1;
        
        int carry = 0;
        StringBuilder res = new StringBuilder();
        
        while (i >= 0 || j >= 0) {
            if (i >= 0) {
                carry += Integer.valueOf(String.valueOf(a.charAt(i)));
                i--;
            }
            
            if (j >= 0) {
                carry += Integer.valueOf(String.valueOf(b.charAt(j)));
                j--;
            }
            
            res.insert(0, String.valueOf(carry % 2));
            carry /= 2;
        }
        
        if (carry == 1)
            res.insert(0, "1");
        return res.toString();
    }
}