public class Solution {
    public int findPeakElement(int[] nums) {
        return findPeakElement(nums, 0, nums.length - 1);
    }
    
    private int findPeakElement(int[] nums, int left, int right) {
        if (left == right)
            return left;
        if (right - left == 1)
            return nums[right] >= nums[left]? right: left;
        
        int mid = (left + right) / 2;
        if ((nums[mid] >= nums[mid+1]) && (nums[mid] >= nums[mid-1]))
            return mid;
        else if (nums[mid] < nums[mid - 1])
            return findPeakElement(nums, left, mid - 1);
        else
            return findPeakElement(nums, mid + 1, right);
    }
}


/*
public class Solution {
    public int findPeakElement(int[] nums) {
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if ((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == nums.length - 1 || nums[mid] >= nums[mid + 1]))
                return mid;
            else if (mid > 0 && nums[mid] < nums[mid - 1])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return 0;
    }
}
*/