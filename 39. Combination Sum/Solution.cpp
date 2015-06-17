// LeetCode #39: Combination Sum

/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        if (candidates.empty())
            return res;
            
        sort(candidates.begin(), candidates.end());
        
        vector<int> cur;
        dfs(candidates, 0, target, cur, res);
        return res;
    }
    
private:
    void dfs(vector<int> &candidates, int start, int target, vector<int> &cur, vector<vector<int>> &res) {
        if (target == 0) {
            if (find(res.begin(), res.end(), cur) == res.end())
                res.push_back(cur);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            //if (i > start && candidates[i] == candidates[i-1])
                //continue;
            
            if (target >= candidates[i]) {
                cur.push_back(candidates[i]);
                dfs(candidates, i, target-candidates[i], cur, res);
                cur.pop_back();
            }
        }
    }
};