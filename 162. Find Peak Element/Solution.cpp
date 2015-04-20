class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return findPeakElement(nums, 0, nums.size() - 1);
    }

private:
    int findPeakElement(vector<int>& nums, int left, int right) {
        if (left == right)
            return left;
        if (right - left == 1)
            return nums[right] >= nums[left]? right: left;
            
        int mid = (left + right) / 2;
        if ((nums[mid] > nums[mid+1]) && (nums[mid] > nums[mid-1]))
            return mid;
        else if (nums[mid] < nums[mid-1])
            return findPeakElement(nums, left, mid-1);
        else
            return findPeakElement(nums, mid+1, right);
    }

};


/*
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if ((mid == 0 || nums[mid - 1] <= nums[mid]) && (mid == nums.size() - 1 || nums[mid + 1] <= nums[mid]))
                return mid;
            else if (mid > 0 && nums[mid] < nums[mid - 1])
                right = mid - 1;
            else
                left = mid + 1;
        }
    }
};
*/