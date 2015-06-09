// LeetCode #69: Sqrt(x)

/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

int mySqrt(int x) {
    if (x < 0) return -1;
    if (x == 0) return 0;
    
    int left = 0;
    int right = (x / 2) + 1;
    
    while (left <= right) {
        long mid = (left + right) / 2;
        if (mid * mid == x)
            return (int)mid;
        else if (mid * mid > x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return right;
}