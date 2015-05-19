class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int bitSum = 0;
            for (int j = 0; j < nums.size(); j++) {
                bitSum += (nums[j] >> i) & 1;
            }
            
            res = res | ((bitSum % 3) << i);
        }
        return res;
    }
};