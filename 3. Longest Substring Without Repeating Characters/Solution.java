// LeetCode #3: Longest Substring Without Repeating Characters

/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() <= 1)
            return s.length();
        
        int pre = 0;
        int maxLen = 0;
        boolean[] flag = new boolean[256];
        
        for (int i = 0; i < s.length(); i++) {
            if (!flag[s.charAt(i)]) {
                flag[s.charAt(i)] = true;
            } else {
                //while (s.charAt(i) != s.charAt(pre)) {
                  //  flag[s.charAt(pre)] = false;
                    //pre++;
                //}
                pre++;
            }
            maxLen = Math.max(maxLen, i - pre + 1);
        }
        return maxLen;
    }
}

/*
// Time Limit Exceeded
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        
        int maxLen = 0;
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        for (int i = 0; i < s.length(); i++) {
            if (!map.containsKey(s.charAt(i))) {
                map.put(s.charAt(i), i);
            } else {
                maxLen = Math.max(maxLen, map.size());
                i = map.get(s.charAt(i));
                map.clear();
            }
        }
        return Math.max(maxLen, map.size());
    }
}
*/

