// LeetCode #65: Valid Number

/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. 
You should gather all requirements up front before implementing one.
*/

class Solution {
public:
    bool isNumber(string s) {
        int i = 0, n = s.size();
        
        while (i < n && s[i] == ' ') i++;
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;
        
        bool isValid = false;
        
        while (i < n && isdigit(s[i])) {
            i++;
            isValid = true;
        }
        
        if (i < n && s[i] == '.') {
            i++;
            while (i < n && isdigit(s[i])) {
                i++;
                isValid = true;
            }
        }
        
        if (isValid && i < n && s[i] == 'e') {
            i++;
            isValid = false;
            if (i < n && (s[i] == '+') || (s[i] == '-')) i++;
            while (i < n && isdigit(s[i])) {
                i++;
                isValid = true;
            }
        }
        
        while (i < n && s[i] == ' ') i++;
        
        return isValid && i == n;
    }
};