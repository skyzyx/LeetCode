// LeetCode #10: Regular Expression Matching

/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.size() == 0) 
            return s.size() == 0;
        
        if (p.size() == 1) 
            return s.size() == 1 && (p[0] == '.' || p[0] == s[0]);
        
        if (p[1] == '*') {
            if (isMatch(s, p.substr(2))) return true;
            return s.size() > 0 && (p[0] == '.' || p[0] == s[0]) && isMatch(s.substr(1), p);
        } else {
            return s.size() > 0 && (p[0] == '.' || p[0] == s[0]) && isMatch(s.substr(1), p.substr(1));
        }
    }
};