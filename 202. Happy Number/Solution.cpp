class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hset;
        
        while (n != 1 && hset.find(n) == hset.end()) {
            hset.insert(n);
            
            int digit = 0;
            int sum = 0;
            while (n != 0) {
                digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};