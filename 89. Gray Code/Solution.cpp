class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if (n == 0) {
            res.push_back(0);
            return res;
        }
        
        vector<int> preRes = grayCode(n-1);
        res.insert(res.end(), preRes.begin(), preRes.end());
        
        for (int i = preRes.size() - 1; i >= 0; i--)
            res.push_back(preRes[i] + pow(2, n-1));
            
        return res;
            
    }
};