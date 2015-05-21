class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            int temp = s[i] - 'A' + 1;
            res = res * 26 + temp;
        }
        return res;
        
    }
};