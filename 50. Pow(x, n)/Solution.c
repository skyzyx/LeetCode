// LeetCode #50: Pow(x, n)

// Implement pow(x, n).

double myPow(double x, int n) {
    if (n == 0)
        return 1.0;
    if (n == 1)
        return x;
        
    int sign = n;
    if (n < 0)
        n = -n;
        
    double res = myPow(x, n/2);
    if (n % 2 == 0)
        res = res * res;
    else
        res = res * res * x;
        
    return sign > 0? res: 1/res;
}