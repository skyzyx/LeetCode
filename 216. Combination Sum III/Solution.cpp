// LeetCode #216: Combination Sum III

/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if (k <= 0)
            return res;
            
        vector<int> cur;
        dfs(k, n, 1, cur, res);
        return res;
    }
    
private:
    void dfs(int k, int target, int start, vector<int> &cur, vector<vector<int>> &res) {
        if (target == 0 && cur.size() == k) {
            res.push_back(cur);
            return;
        }
        
        for (int i = start; i <= 9; i++) {
            if (target >= i) {
                cur.push_back(i);
                dfs(k, target-i, i+1, cur, res);
                cur.pop_back();
            }
        }
    }
};