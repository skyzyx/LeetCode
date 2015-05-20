class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
            
        return max(houseRob(nums, 0, n-2), houseRob(nums, 1, n-1));
    }
    
private:
    int houseRob(vector<int> &nums, int from, int to) {
        int even = 0;
        int odd = 0;
        for (int i = from; i <= to; i++) {
            if (i % 2 == 0)
                even = max(even + nums[i], odd);
            else
                odd = max(odd + nums[i], even);
        }
        return max(even, odd);
    }
};