class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> res;
        if (k <= 0)
            return res;
            
        vector<int> cur;
        dfs(1, n, k, cur, res);
        return res;
    }
    
private:
    void dfs(int start, int n, int k, vector<int> &cur, vector<vector<int>> &res) {
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }
        
        for (int i = start; i <= n; i++) {
            cur.push_back(i);
            dfs(i+1, n, k, cur, res);
            cur.pop_back();
        }
    }
};