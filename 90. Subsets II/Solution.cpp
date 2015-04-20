class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int>> res (1);
        sort(S.begin(), S.end());
        
        int pre = S[0];
        int preResSize = 1;
        
        for (int i = 0; i < S.size(); i++) {
            if (S[i] != pre) {
                preResSize = res.size();
                pre = S[i];
            }
            
            int size = res.size();
            for (int j = size - 1; j >= size - preResSize; j--) {
                res.push_back(res[j]);
                res.back().push_back(S[i]);
            }
        }
        return res;
    }
};