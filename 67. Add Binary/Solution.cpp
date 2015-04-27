class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        
        int i = a.size() - 1;
        int j = b.size() - 1;
        
        int carry = 0;
        while (i >= 0 || j >= 0) {
            if (i >= 0) {
                carry += a[i] - '0';
                i--;
            }
            
            if (j >= 0) {
                carry += b[j] - '0';
                j--;
            }
            
            res = to_string(carry % 2) + res;
            carry /= 2;
        }
        
        if (carry == 1)
            res = to_string(carry) + res;
            
        return res;
        
    }
};