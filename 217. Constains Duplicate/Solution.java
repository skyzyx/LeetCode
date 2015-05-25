public class Solution {
    public boolean containsDuplicate(int[] nums) {
        if (nums == null || nums.length < 2)
            return false;
            
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i]))
                return true;
            else
                map.put(nums[i], 1);
        }
        return false;
    }
}

/*
public class Solution {
    public boolean containsDuplicate(int[] nums) {
        if (nums.length < 2)
            return false;
            
        Arrays.sort(nums);
        for (int i = 1; i < nums.length; i++)
            if (nums[i] == nums[i-1])
                return true;
                
        return false;
    }
}
*/
