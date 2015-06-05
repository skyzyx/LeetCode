// LeetCode #168: Excel Sheet Column Title

/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB
*/

public class Solution {
    public String convertToTitle(int n) {
        if (n <= 0)
            return null;
            
        StringBuilder res = new StringBuilder();
        while (n > 0) {
            n--;
            char letter = (char) (n % 26 + 'A');
            res.append(letter);
            n /= 26;
        }
        res.reverse();
        return res.toString();
    }
}