// LeetCode #76: Minimum Window Substring

/*
Given a string S and a string T, find the minimum window in S which will contain 
all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, 
return the emtpy string "".

If there are multiple such windows, you are guaranteed that there 
will always be only one unique minimum window in S.
*/

public class Solution {
    public String minWindow(String s, String t) {
        if (s == null || s.length() == 0) return s;
        
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        for (int i = 0; i < t.length(); i++) {
            if (!map.containsKey(t.charAt(i)))
                map.put(t.charAt(i), 1);
            else
                map.put(t.charAt(i), map.get(t.charAt(i)) + 1);
        }
        
        int left = 0, count = 0;
        int minStart = 0, minLen = s.length() + 1;
        
        for (int right = 0; right < s.length(); right++) {
            if (map.containsKey(s.charAt(right))) {
                map.put(s.charAt(right), map.get(s.charAt(right)) - 1);
                if (map.get(s.charAt(right)) >= 0) count++;
                
                while (count == t.length()) {
                    if (right - left + 1 < minLen) {
                        minLen = right - left + 1;
                        minStart = left;
                    }
                    if (map.containsKey(s.charAt(left))) {
                        map.put(s.charAt(left), map.get(s.charAt(left)) + 1);
                        if (map.get(s.charAt(left)) > 0) count--;
                    }
                    left++;
                }
            }
        }
        
        if (minLen > s.length()) return "";
        return s.substring(minStart, minStart + minLen);
    }
}