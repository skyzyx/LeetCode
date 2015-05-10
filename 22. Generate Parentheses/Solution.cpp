class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n <= 0)
            return res;
            
        res.push_back("()");
        
        for (int i = 1; i < n; i++) {
            vector<string> tmp;
            for (string word: res) {
                for (int j = 0; j <= word.size(); j++) {
                    string curr = word.substr(0, j) + "()" + word.substr(j);
                    if (find(tmp.begin(), tmp.end(), curr) == tmp.end())
                        tmp.push_back(curr);
                }
            }
            res = tmp;
        }
        return res;
    }
};