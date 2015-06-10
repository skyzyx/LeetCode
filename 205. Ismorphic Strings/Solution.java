// LeetCode #205: Ismorphic Strings

/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/

public class Solution {
    public boolean isIsomorphic(String s, String t) {
        if (s == null || t == null || s.length() != t.length())
            return false;
            
        Map<Character, Character> smap = new HashMap<Character, Character>();
        Map<Character, Character> tmap = new HashMap<Character, Character>();
        
        for (int i = 0; i < s.length(); i++) {
            if (smap.containsKey(s.charAt(i)))
                if (smap.get(s.charAt(i)) != t.charAt(i))
                    return false;
            if (tmap.containsKey(t.charAt(i)))
                if (tmap.get(t.charAt(i)) != s.charAt(i))
                    return false;
                
            smap.put(s.charAt(i), t.charAt(i));
            tmap.put(t.charAt(i), s.charAt(i));
        }
        return true;
    }
}