class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        if (candidates.empty())
            return res;
            
        sort(candidates.begin(), candidates.end());
        
        vector<int> cur;
        recursiveCombination(candidates, 0, target, cur, res);
        return res;
    }
    
private:
    void recursiveCombination(vector<int> &candidates, int start, int target, vector<int> &cur, vector<vector<int>> &res) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i-1])
                continue;
            
            if (target >= candidates[i]) {
                cur.push_back(candidates[i]);
                recursiveCombination(candidates, i, target-candidates[i], cur, res);
                cur.pop_back();
            }
        }
            
    }
};