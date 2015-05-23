class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        
        while (i < n) {
            if (nums[i] != i+1 && nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
                swap(nums, i, nums[i]-1);
            else
                i++;
        }
        
        for (int j = 0; j < n; j++)
            if (nums[j] != j+1)
                return j+1;
                
        return n+1;
    }
    
private:
    void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};