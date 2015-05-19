class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &S) {
        vector<vector<int>> res;
        vector<int> tmp;
        res.push_back(tmp);
        if (S.size() == 0)
            return res;
            
        sort(S.begin(), S.end());
        
        for (int i = 0; i < S.size(); i++) {
            int size = res.size();
            for (int j = 0; j < size; j++) {
                vector<int> cur = res[j];
                cur.push_back(S[i]);
                if (find(res.begin(), res.end(), cur) == res.end())
                    res.push_back(cur);
            }
        }
        return res;
    }
};

/*
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
*/