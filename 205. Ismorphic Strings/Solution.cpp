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

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
            
        unordered_map<char, char> smap;
        unordered_map<char, char> tmap;
        
        for (int i = 0; i < s.size(); i++) {
            if (smap.find(s[i]) != smap.end())
                if (smap[s[i]] != t[i])
                    return false;
                    
            if (tmap.find(t[i]) != tmap.end())
                if (tmap[t[i]] != s[i])
                    return false;
                    
            smap[s[i]] = t[i];
            tmap[t[i]] = s[i];
        }
        return true;
    }
};