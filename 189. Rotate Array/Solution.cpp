class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 0 || nums.size() == 1 || k == 0)
            return;
            
        int n = nums.size();
        int order = k % n;
        reverse(nums, 0, n - order - 1);
        reverse(nums, n - order, n - 1);
        reverse(nums, 0, n - 1);
        return;
    }
    
private:
    void reverse(vector<int>& nums, int l, int r) {
        while (l < r) {
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            
            l++;
            r--;
        }
    }
};