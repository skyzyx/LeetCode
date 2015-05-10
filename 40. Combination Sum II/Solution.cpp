class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> res;
        if (num.empty())
            return res;
            
        sort(num.begin(), num.end());
        
        vector<int> cur;
        recursiveCombination(num, 0, target, cur, res);
        return res;
    }
    
private:
    void recursiveCombination(vector<int> &num, int start, int target, vector<int> &cur, vector<vector<int>> &res) {
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
                recursiveCombination(num, i+1, target-num[i], cur, res);
                cur.pop_back();
            }
        }
    }
};