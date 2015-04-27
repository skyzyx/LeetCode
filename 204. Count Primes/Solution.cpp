class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1)
            return 0;
            
        bool isPrime[n];
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i < n; i++)
            isPrime[i] = true;
        
        for (int i = 2; i * i < n; i++) {
            int tmp = i * i;
            if (isPrime[tmp]) {
                while (tmp < n) {
                    isPrime[tmp] = false;
                    tmp += i;
                }
            }
        }
        
        int ans = 0;
        for (int i = 2; i < n; i++)
            if (isPrime[i])
                ans++;
                
        return ans;
        
    }
};