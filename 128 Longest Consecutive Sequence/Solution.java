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