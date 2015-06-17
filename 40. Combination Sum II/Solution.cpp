// LeetCode #40: Combination Sum II

/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> res;
        if (num.empty())
            return res;
            
        sort(num.begin(), num.end());
        
        vector<int> cur;
        dfs(num, 0, target, cur, res);
        return res;
    }
    
private:
    void dfs(vector<int> &num, int start, int target, vector<int> &cur, vector<vector<int>> &res) {
        if (target == 0) {
            if (find(res.begin(), res.end(), cur) == res.end())
                res.push_back(cur);
            return;
        }
        
        for (int i = start; i < num.size(); i++) {
            //if (i > start && num[i] == num[i-1])
                //continue;
            /*    
            Input:  [1,1], 1
            Output: [[1],[1]]
            Expected:   [[1]]
            */
            if (target >= num[i]) {
                cur.push_back(num[i]);
                dfs(num, i+1, target-num[i], cur, res);
                cur.pop_back();
            }
        }
    }
};