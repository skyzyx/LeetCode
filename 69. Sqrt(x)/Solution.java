// LeetCode #69: Sqrt(x)

/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

public class Solution {
    public int mySqrt(int x) {
        if (x < 0)
            return -1;
        if (x == 0)
            return 0;
            
        long left = 0;
        long right = x / 2 + 1; // sqrt(x) < x/2 + 1
        
        while (left <= right) {
            long mid = (left + right) / 2;
            long square = mid * mid;
            if (square == x)
                return (int)mid;
            else if (square > x)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return (int)right;
    }
}