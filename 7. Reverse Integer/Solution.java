public class Solution {
    public int reverse(int x) {
        int digit = 0;
        long res = 0;
        while (x != 0) {
            digit = x % 10;
            res = res * 10 + digit;
            x = x / 10;
        }
        
        if (res > Integer.MAX_VALUE || res < Integer.MIN_VALUE)
            return 0;
        else 
            return (int)res;
    }
}