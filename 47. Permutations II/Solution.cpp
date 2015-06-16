// LeetCode #47: Permutations II

/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0)
            return res;
            
        sort(nums.begin(), nums.end()); // Time Limit Exceeded, Last executed input:	[-1,-1,3,-1]
        
        bool visited[nums.size()] = {false};
        vector<int> cur;
        dfs(nums, visited, cur, res);
        return res;
    }
    
private:
    void dfs(vector<int> &nums, bool* visited, vector<int> &cur, vector<vector<int>> &res) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] == true || (i > 0 && nums[i] == nums[i-1] && visited[i-1] == false))
                continue;
                
            visited[i] = true;
            cur.push_back(nums[i]);
            dfs(nums, visited, cur, res);
            cur.pop_back();
            visited[i] = false;
        }
    }
};