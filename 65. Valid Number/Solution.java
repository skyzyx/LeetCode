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

public class Solution {
    public boolean isNumber(String s) {
        int i = 0, n = s.length();
        while (i < n && s.charAt(i) == ' ') i++;
        if (i < n && (s.charAt(i) == '+' || s.charAt(i) == '-')) i++;
        
        boolean isValid = false;
        
        while (i < n && Character.isDigit(s.charAt(i))) {
            i++;
            isValid = true;
        }
        
        if (i < n && s.charAt(i) == '.') {
            i++;
            while (i < n && Character.isDigit(s.charAt(i))) {
                i++;
                isValid = true;
            }
        }
        
        if (isValid && i < n && s.charAt(i) == 'e') {
            i++;
            isValid = false;
            if (i < n && (s.charAt(i) == '+' || s.charAt(i) == '-')) i++;
            while (i < n && Character.isDigit(s.charAt(i))) {
                i++;
                isValid = true;
            }
        }
        
        while (i < n && s.charAt(i) == ' ') i++;
        return isValid && i == n;
    }
}