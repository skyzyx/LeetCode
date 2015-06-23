// LeetCode #219: Contains Duplicate II

/*
Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
*/

public class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        if (nums == null || nums.length < 2)
            return false;
            
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            if (!map.containsKey(nums[i])) {
                map.put(nums[i], i);
            } else {
                if (i - map.get(nums[i]) <= k)
                    return true;
                
                map.put(nums[i], i);
            }
        }
        return false;
    }
}

/*
public class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        if (nums == null || nums.length < 2)
            return false;
            
        for (int i = 0; i < nums.length; i++) {
            for (int j = i+1; j < nums.length && j <= i+k; j++) {
                if (nums[i] == nums[j])
                    return true;
            }
        }
        return false;
    }
}
*/