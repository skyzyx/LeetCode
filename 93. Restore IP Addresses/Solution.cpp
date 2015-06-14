// LeetCode #93: Restore Ip Addresses

/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size() < 4 || s.size() > 12)
            return res;
            
        dfs(s, "", res, 0);
        return res;
    }
    
private:
    void dfs(string s, string tmp, vector<string>& res, int count) {
        if (count == 3 && isValid(s)) {
            res.push_back(tmp + s);
            return;
        }
        
        for (int i = 1; i < 4 && i < s.size(); i++) {
            string sub = s.substr(0, i);
            if (isValid(sub))
                dfs(s.substr(i), tmp + sub + ".", res, count + 1);
        }
    }
    
    bool isValid(string s) {
        if (s.size() < 0 || s.size() > 3)
            return false;
        if (s[0] == '0')
            return s.compare("0") == 0;
        int num = stoi(s);
        return num > 0 && num <= 255;
    }
};