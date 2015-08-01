// LeetCode #242: Valid Anagram

/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*/

/*
public class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        for (int i = 0; i < s.length(); i++) {
            if (map.containsKey(s.charAt(i)))
                map.put(s.charAt(i), map.get(s.charAt(i)) + 1); // cannot find symbol: method set(char,int)
            else
                map.put(s.charAt(i), 1);
        }
        
        for (int i = 0; i < t.length(); i++) {
            if (!map.containsKey(t.charAt(i)))
                return false;
            else {
                if (map.get(t.charAt(i)) == 0)
                    return false;
                else
                    map.put(t.charAt(i), map.get(t.charAt(i)) - 1);
            }
        }
        return true;
    }
}
*/

public class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        
        char[] sarr = s.toCharArray();
        char[] tarr = t.toCharArray();
        
        Arrays.sort(sarr);
        Arrays.sort(tarr);
        
        return String.valueOf(sarr).equals(String.valueOf(tarr));
    }
}
