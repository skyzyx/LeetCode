// LeetCode #81: Search in Rotated Sorted Array II

/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return false;
            
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target)
                return true;
                
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
        return false;
    }
};