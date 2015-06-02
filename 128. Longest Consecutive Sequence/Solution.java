// LeetCode #128: Longest Consecutive Sequence

/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

public class Solution {
    public int longestConsecutive(int[] num) {
        if (num == null || num.length == 0)
            return 0;
            
        Set<Integer> set = new HashSet<Integer>();
        for (int i = 0; i < num.length; i++)
            set.add(num[i]);
            
        int maxLen = 0;
        for (int i = 0; i < num.length; i++) {
            int left = num[i] - 1;
            int right = num[i] + 1;
            int count = 1;
            
            while (set.contains(left)) {
                set.remove(left);
                left -= 1;
                count += 1;
            }
            
            while (set.contains(right)) {
                set.remove(right);
                right += 1;
                count += 1;
            }
            
            maxLen = Math.max(maxLen, count);
            
        }
        return maxLen;
    }
}