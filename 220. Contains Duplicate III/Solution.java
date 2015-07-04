// LeetCode #220: Contains Duplicate III

/*
Given an array of integers, find out whether there are two distinct indices i and j 
in the array such that the difference between nums[i] and nums[j] is at most t and 
the difference between i and j is at most k.
*/

public class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        TreeSet<Integer> s = new TreeSet<Integer>();
        
        for (int i = 0; i < nums.length; i++) {
            if ((s.floor(nums[i]) != null && nums[i] <= s.floor(nums[i]) + t) || 
               (s.ceiling(nums[i]) != null && nums[i] >= s.ceiling(nums[i]) - t))
                return true;
                
            s.add(nums[i]);
            
            if (i >= k)
                s.remove(nums[i-k]);
        }
        return false;
    }    
}

/*
public class Solution { // Time Limit Exceeded
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i+1; j <= k+i && j < nums.length; j++) {
                if (Math.abs(nums[j] - nums[i]) <= t)
                    return true;
            }
        }
        return false;
    }
}
*/