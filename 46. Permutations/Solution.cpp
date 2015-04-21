class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> res;
        if (num.size() == 0)
            return res;
            
        vector<int> cur;
        dfs(num, cur, res);
        return res;
    }
    
private:
    void dfs(vector<int> &num, vector<int> &cur, vector<vector<int>> &res) {
        if (cur.size() == num.size()) {
            res.push_back(cur);
            return;
        }
        
        for (int i = 0; i < num.size(); i++) {
            if (find(cur.begin(), cur.end(), num[i]) != cur.end())
                continue;
                
            cur.push_back(num[i]);
            dfs(num, cur, res);
            cur.pop_back();
        }
    }
};