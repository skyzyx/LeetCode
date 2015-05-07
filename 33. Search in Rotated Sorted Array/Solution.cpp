class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
            
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target)
                return m;
                
            if (nums[l] < nums[m]) {
                if (target >= nums[l] && target <= nums[m])
                    r = m-1;
                else
                    l = m+1;
            } else if (nums[l] > nums[m]) {
                if (target >= nums[m] && target <= nums[r])
                    l = m+1;
                else
                    r = m-1;
            } else {
                l++;
            }
        }
        return -1;
    }
};