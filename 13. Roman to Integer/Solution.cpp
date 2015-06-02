// LeetCode #13: Roman to Integer

/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    
    int romanToInt(string s) {
        int n = s.length() - 1;
        int res = charToInt(s[n]);
        
        for (int i = 0; i < n; i++) {
            int sign = 1;
            if (charToInt(s[i]) < charToInt(s[i+1]))
                sign = -1;
            res += charToInt(s[i]) * sign;
        }
        return res;
        
    }
    
    int charToInt(char c) {
        switch(c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
};