// LeetCode #242: Valid Anagram

/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> map;
        
        for (int i = 0; i < s.size(); i++)
            if (map.find(s[i]) == map.end())
                map[s[i]] = 1;
            else
                map[s[i]]++;
            
        for (int i = 0; i < t.size(); i++)
            if (map.find(t[i]) == map.end())
                return false;
            else {
                if (map[t[i]] >= 1)
                    map[t[i]]--;
                else
                    return false;
            }
            
        return true;
    }
};

/*
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
*/