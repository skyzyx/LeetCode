class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxdist = 0;
        for (int i = 0; i <= maxdist && i < nums.size(); i++) {
            maxdist = max(maxdist, i + nums[i]);
            if (maxdist >= nums.size() - 1)
                return true;
        }
        return false;
    }
};