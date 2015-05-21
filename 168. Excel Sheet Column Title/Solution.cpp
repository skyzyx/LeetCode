class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while (n > 0) {
            n--;
            char letter = (char)(n % 26 + 'A');
            res.insert(res.begin(), letter);
            n /= 26;
        }
        return res;
    }
};