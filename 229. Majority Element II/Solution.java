// LeetCode #229: Majority Element II

/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

Hint:

How many majority elements could it possibly have?
Do you have a better hint? Suggest it!
*/

public class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> res = new ArrayList<Integer>();
        if (nums == null || nums.length == 0) return res;
        
        int data1 = 0, data2 = 0, count1 = 0, count2 = 0;
        
        for (int i = 0; i < nums.length; i++) {
            if (count1 == 0) data1 = nums[i];
            if (count2 == 0) data2 = nums[i];
            
            if (nums[i] == data1) count1++;
            else if (nums[i] == data2) count2++;
            else {
                count1--;
                count2--;
            }
        }
        
        count1 = 0; 
        count2 = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == data1) count1++;
            else if (nums[i] == data2) count2++;
        }
        
        if (count1 > nums.length / 3) res.add(data1);
        if (count2 > nums.length / 3) res.add(data2);
        return res;
    }
}