public class Solution {
    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
        List<String> res = new ArrayList<String>();
        
        int pre = lower - 1;
        for (int i = 0; i <= nums.length; i++) {
            int cur = i == nums.length? upper+1: nums[i];
            if (cur - pre >= 2)
                res.add(getRange(pre+1, cur-1));
            pre = cur;
        }
        
        return res;
    }
    
    private String getRange(int i, int j) {
        return i == j? String.valueOf(i): i + "->" + j;
    }
}