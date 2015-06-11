// LeetCode #77: Combinations

/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

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