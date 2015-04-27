class Solution {
public:
    string countAndSay(int n) {
        if (n < 1)
            return "";
            
        string res = "1";
        for (int i = 1; i < n; i++) {
            string tmp = "";
            int count = 1;
            for (int j = 1; j < res.size(); j++) {
                if (res[j] == res[j-1])
                    count++;
                else {
                    tmp += to_string(count) + res[j-1];
                    count = 1;
                }
            }
            tmp += to_string(count) + res[res.size() - 1];
            res = tmp;
        }
        return res;
    }
};