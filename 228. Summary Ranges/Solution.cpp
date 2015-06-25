// LeetCode #228: Summary Ranges

/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.size() == 0)
            return res;
            
        for (int i = 0; i < nums.size(); i++) {
            string tmp = to_string(nums[i]);
            int countNum = 0;
            
            while (i+1 < nums.size() && nums[i+1] - nums[i] == 1) {
                i++;
                countNum++;
            }
            
            if (countNum > 0)
                tmp = tmp + "->" + to_string(nums[i]);
                
            res.push_back(tmp);
        }
        return res;
    }
};