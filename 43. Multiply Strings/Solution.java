// LeetCode #43: Multiply Strings

/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

public class Solution {
    public String multiply(String num1, String num2) {
        if (num1 == null || num2 == null || num1.length() == 0 || num2.length() == 0)
            return null;
            
        num1 = new StringBuilder(num1).reverse().toString();
        num2 = new StringBuilder(num2).reverse().toString();
        
        int m = num1.length();
        int n = num2.length();
        
        int[] data = new int[m + n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                data[i+j] += (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
            }
        }
        
        StringBuilder res = new StringBuilder();
        int digit = 0;
        int carry = 0;
        for (int i = 0; i < data.length; i++) {
            digit = data[i] % 10;
            carry = data[i] / 10;
            
            res.insert(0, digit);
            
            if (i < data.length - 1)
                data[i+1] += carry;
        }
        
        while (res.charAt(0) == '0' && res.length() > 1)
            res.deleteCharAt(0);
        
        return res.toString();
        
    }
}