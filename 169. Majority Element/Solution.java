// LeetCode #169: Majority Element

/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

public class Solution {
    public int majorityElement(int[] num) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < num.length; i++) {
            if (!map.containsKey(num[i]))
                map.put(num[i], 0); // Why not map.put(num[i], 1)
            else
                map.put(num[i], map.get(num[i]) + 1);
                
            if (map.get(num[i]) >= num.length / 2)
                return num[i];
        }
        return num[0];
    }
}

/*
public class Solution {
    public int majorityElement(int[] num) {
        int majIndex = 0;
        int majCount = 1;
        
        for (int i = 1; i < num.length; i++) {
            if (num[majIndex] == num[i]) {
                majCount++;
            } else {
                majCount--;
            }
            
            if (majCount == 0) {
                majIndex = i;
                majCount = 1;
            }
        }
        
        return num[majIndex];
    }
}
*/