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