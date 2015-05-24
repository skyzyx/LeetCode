class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() == 0 || num2.size() == 0)
            return "";
            
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int len = num1.size() + num2.size();
        int data[len] = {0};
        
        for (int i = 0; i < num1.size(); i++) {
            for (int j = 0; j < num2.size(); j++)
                data[i+j] = data[i+j] + (num1[i] - '0') * (num2[j] - '0'); 
        }
        
        string res = "";
        int digit = 0;
        int carry = 0;
        for (int i = 0; i < len; i++) {
            digit = data[i] % 10;
            carry = data[i] / 10;
            
            res.insert(0, to_string(digit)); // Not res.insert(res.begin(), to_string(digit))
            
            if (i < len - 1)
                data[i+1] += carry;
        }
        
        while (res[0] == '0' && res.size() > 1)
            res.erase(0, 1);
        
        return res;
    }
};