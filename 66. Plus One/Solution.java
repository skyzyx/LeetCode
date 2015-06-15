// LeetCode #66: Plus One

/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

public class Solution {
    public int[] plusOne(int[] digits) {
        if (digits == null || digits.length == 0)
            return digits;
            
        int carry = 1;
        for (int i = digits.length - 1; i >= 0; i--) {
            if (digits[i] + carry == 10) {
                digits[i] = 0;
                carry = 1;
            } else {
                digits[i] += carry;
                return digits;
            }
        }
        
        int[] res = new int[digits.length + 1];
        res[0] = 1;
        return res;
    }
}