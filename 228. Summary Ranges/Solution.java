// LeetCode #228: Summary Ranges

/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

public class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> res = new ArrayList<String>();
        if (nums == null || nums.length == 0)
            return res;
            
        for (int i = 0; i < nums.length; i++) {
            String tmp = new String(String.valueOf(nums[i]));
            int countNum = 0;
            
            while (i+1 < nums.length && nums[i+1] - nums[i] == 1) {
                i++;
                countNum++;
            }
            
            if (countNum > 0)     
                tmp = tmp + "->" + nums[i];
                
            res.add(tmp);
        }
        return res;
    }
}