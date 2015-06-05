// LeetCode #171: Excel Sheet Column Number

/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

public class Solution {
    public int titleToNumber(String s) {
        if (s == null || s.length() == 0)
            return 0;
        
        int res = 0;
        int tmp = 0;
        for (int i = 0; i < s.length(); i++) {
            tmp = s.charAt(i) - 'A' + 1;
            res = res * 26 + tmp;
        }
        return res;
    }
}