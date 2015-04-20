class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> res;
        vector<int> tmp;
        res.push_back(tmp);
        
        for (int i = 0; i < S.size(); i++) {
            int size = res.size();
            for (int j = 0; j < size; j++) {
                res.push_back(res[j]);
                res.back().push_back(S[i]);
            }
        }
        return res;
    }
};