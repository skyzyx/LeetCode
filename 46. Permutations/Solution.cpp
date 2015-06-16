// LeetCode #46: Permutations

/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

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
            if (find(cur.begin(), cur.end(), num[i]) == cur.end()) {
                cur.push_back(num[i]);
                dfs(num, cur, res);
                cur.pop_back();
            }
        }
    }
};